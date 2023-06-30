#include "../include/TCP.hpp"
#include <limits>
#include <cstdlib>
#include <ctime>
#include <iostream>

const int PACKET_LOSS = 1;

TCP::TCP(int cwnd, int ssthresh, int rtt) :
    _cwnd(cwnd),
    _ssthresh(ssthresh),
    _rtt(rtt)
{
    srand(time(0));
    _seqNum = 0;
    _isOnRestransmitThisRTT = false;
}

/// @brief 
// Will be used for all of the tcp extensions if not needed to be implemented differently 
/// @return 
vector<int> TCP::SendData()
{
    vector<int> sent;
    srand(time(0));
    // timeout
    if((rand() % (INT16_MAX)) < _cwnd*2)
    {
        cout << "timeout occured!" << endl;
        return sent;
    }    
    
    if(_isOnRestransmitThisRTT)
    {
        // although it wasn't timeout 
        return sent;    
    }

    if(_cwnd < _ssthresh)
    {
        int i;
        for(i = 0; i < _cwnd; i++)
        {
            // packet loss
            srand(time(0) + 123 * i);
            if((rand() % 100) + 1 <= PACKET_LOSS)
            {
                cout << "Packet Loss on packet: " << i << endl;
                continue;
            }
            else
            {
                // cout << "packet: " << i << "sent" << endl;
                sent.push_back(i + _seqNum);
            }
        }
        _seqNum += i;
    }
    
    return sent;
}

vector<int> TCP::onPacketLoss(const vector<int> sent)
{
    vector<int> lostPackets;
    if(sent.empty())
    {
        return lostPackets;
    }
    // Missing packets from the beginning
    int firstPackets = sent[0] - (_seqNum - _cwnd);
    for(int f = 0; f < firstPackets; f++)
    {
        lostPackets.push_back((_seqNum - _cwnd) + f);
    }
    // Missing packets from middle
    int i = 1;
    while(i < sent.size())
    {
        if(sent[i] - sent[i-1] > 1)
        {
            for(int j = 0; j < sent[i]-sent[i-1]; j++)
            {
                lostPackets.push_back(sent[i] + j + 1);
            }
        }
        i++;
    }
    // Missing packets from the end
    while(i < _cwnd)
    {
        lostPackets.push_back((_seqNum - _cwnd) + i);
        i++;
    }
    _lostPackets = lostPackets;
    return lostPackets;
}

void TCP::fastRetransmission()
{
    _isOnRestransmitThisRTT = false;
    for(int rPack : _lostPackets)
    {
        cout << "packet: " << rPack
            <<": Retransmited!" << endl;
    }
    _lostPackets.clear();
}

int TCP::onSelectiveAck()
{
    return 0;
}
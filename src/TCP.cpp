#include "../include/TCP.hpp"
#include <limits>
#include <cstdlib>
#include <ctime>
#include <iostream>

const int PACKET_LOSS = 15;

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
    if((rand() % ((INT16_MAX) / 32)) < _cwnd*2)
    {
        cout << "timeout occured!" << endl;
        return sent;
    }    
    
    if(_isOnRestransmitThisRTT)
    {
        // although it wasn't timeout 
        return sent;    
    }

    int i;
    for(i = 0; i < _cwnd; i++)
    {
        // packet loss
        srand(time(0) + 123 * i);
        if((rand() % 1000) + 1 <= PACKET_LOSS)
        {
            cout << "Packet Loss on packet: " << i + _seqNum << endl;
            _lostPackets.push_back(i + _seqNum);
            continue;
        }
        else
        {
            // cout << "packet: " << i << "sent" << endl;
            sent.push_back(i + _seqNum);
        }
    }
    _seqNum += i;
    
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

void TCP::printSessionDetails(const vector<int> sent)
{
    cout << "data sent: " << sent.size()
        << "  cwnd: " << _cwnd 
        << "  ssthresh: " << _ssthresh;
        if(_cwnd < _ssthresh)
        {
            cout << "  mode: slow start" << endl; 
        }
        else
        {
            cout << "  mode: AIMD" << endl; 
        }
}

void TCP::adjustParameters(const vector<int> sent)
{
    // time out
    if(sent.empty())
    {
        if(_cwnd >= _ssthresh)
        {
            _cwnd /= 2;
            return;
        }
        _ssthresh = _cwnd/2;
        _cwnd = 1;
        return;
    }

    if(sent.size() != _cwnd) // packet loss has occured
    {
        if(_cwnd >= _ssthresh)
        {
            _cwnd = min(_ssthresh/2, _cwnd/2);
            _isOnRestransmitThisRTT = true;
            return;
        }
        else
        {
            _cwnd *= 2;
            _isOnRestransmitThisRTT = true;
            return;
        }

    }
    if(_cwnd < _ssthresh)
    {
        _cwnd *= 2;
    }
    else
    {
        _cwnd += 1;
    }
}

void TCP::onRTTUpdate(int RTT)
{
    int total_iterations = RTT/_rtt;
    for(int i = 0; i < total_iterations; i++)
    {
        cout << "iteration: " << i+1
            << ":" << endl;
        if(_isOnRestransmitThisRTT)
        {
            this->fastRetransmission();
        }
        else
        {
            vector<int> sent = this->SendData();
            _total_sent += sent.size();
            this->printSessionDetails(sent);
            this->adjustParameters(sent);
        }
        cout << "----------" << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~" << endl;
    cout << "total data sent: " << _total_sent << " packets (SMSS)" << endl;
    cout << "time taken: " << RTT << "ms ("
        << RTT/_rtt << " RTTs)" << endl;
    float throughput = static_cast<float>(_total_sent) /
        static_cast<float>(RTT);
    cout << "through of the connection: " << 
    throughput*1000 << " packets/second" << endl;
    cout << "~~~~~~~~~~~~~~~~~~" << endl; 
}
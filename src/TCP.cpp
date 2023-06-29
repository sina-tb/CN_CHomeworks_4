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
        _seqNum = i++;
    }
    else
    {
        srand(time(0));
        if((rand() % 100) + 1 <= PACKET_LOSS)
        {
            cout << "Packet Loss on packet: " << _seqNum << endl;
        }
        else
        {
            sent.push_back(_seqNum);
        }
        _seqNum++;
    }
    
    return sent;
}

int TCP::onSelectiveAck()
{
    return 0;
}
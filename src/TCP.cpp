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
{ srand(time(0)); }

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
        _cwnd = 1;
        return sent;
    }    

    // packet loss
    for(int i = _cwnd; i < _cwnd*2; i++)
    {
        srand(time(0) + 123 * i);
        if(rand() % 100 + 1 <= PACKET_LOSS)
        {
            cout << "packet loss on packet: " << i << endl;
            continue;
        }
        else
        {
            // cout << "packet: " << i << "sent" << endl;
            sent.push_back(i);
        }
    }
    _cwnd *= 2;
    return sent;
}

int TCP::onSelectiveAck()
{
    return 0;
}
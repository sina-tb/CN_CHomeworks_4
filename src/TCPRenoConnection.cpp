#include "../include/TCPRenoConnection.hpp"

#include <iostream>

class TCP;

using namespace std;


TCPRenoConnection::TCPRenoConnection(int cwnd, int ssthresh, int rtt) 
    : TCP(cwnd, ssthresh, rtt)
{   }


int TCPRenoConnection::onRTTUpdate()
{
    return 0;
}

int TCPRenoConnection::onSelectiveAck()
{
    cout << "does not have a SACK Method!" << endl;
    return 0;
}

void TCPRenoConnection::adjustParameters(const vector<int> sent)
{
    // time out
    if(sent.empty())
    {
        _ssthresh = _cwnd/2;
        _cwnd = 1;
        return;
    }

    if(sent.size() != _cwnd) // packet loss has occured
    {
        _cwnd = min(_ssthresh/2, _cwnd/2);
        _isOnRestransmitThisRTT = true;
        return;
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

void TCPRenoConnection::adjustParameters()
{   }

TCPRenoConnection::~TCPRenoConnection()
{

}
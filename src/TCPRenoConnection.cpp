#include "../include/TCPRenoConnection.hpp"

#include <iostream>

class TCP;

using namespace std;


TCPRenoConnection::TCPRenoConnection(int cwnd, int ssthresh, int rtt) 
    : TCP(cwnd, ssthresh, rtt)
{   }


void TCPRenoConnection::fastRetransmission()
{       
    if(_lostPackets.empty())
    {
        _isOnRestransmitThisRTT = false;
        return;
    }
    cout << "packet: " << *(_lostPackets.begin())
        << ": Retransmited!" << endl;
    _lostPackets.erase(_lostPackets.begin());
    if(_lostPackets.empty())
    {
        _isOnRestransmitThisRTT = false;
    }
    _total_sent++;
}

TCPRenoConnection::~TCPRenoConnection()
{
    
}
#include "../include/TCPNewRenoConnection.hpp"
#include<iostream>

using namespace std;
class TCP;

TCPNewRenoConnection::TCPNewRenoConnection(int cwnd, int ssthresh, int rtt)
    : TCP(cwnd, ssthresh, rtt)
{   }

void TCPNewRenoConnection::fastRetransmission()
{
    _isOnRestransmitThisRTT = false;
    _total_sent += _lostPackets.size();
    for(int rPack : _lostPackets)
    {
        cout << "packet: " << rPack
            <<": Retransmited!" << endl;
    }
    _lostPackets.clear();
    return;
}

TCPNewRenoConnection::~TCPNewRenoConnection()
{
       
}
#include "../include/TCPNewRenoConnection.hpp"
#include<iostream>

using namespace std;
class TCP;

TCPNewRenoConnection::TCPNewRenoConnection(int cwnd, int ssthresh, int rtt)
    : TCP(cwnd, ssthresh, rtt)
{   }


int TCPNewRenoConnection::onRTTUpdate()
{
    return 0;
}

void TCPNewRenoConnection::fastRetransmission()
{
    _isOnRestransmitThisRTT = false;
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
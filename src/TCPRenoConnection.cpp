#include "../include/TCPRenoConnection.hpp"

#include <iostream>

class TCP;

using namespace std;


TCPRenoConnection::TCPRenoConnection(int cwnd, int ssthresh, int rtt) 
    : TCP(cwnd, ssthresh, rtt)
{   }

int TCPRenoConnection::onPacketLoss()
{
    return 0;
}

int TCPRenoConnection::onRTTUpdate()
{
    return 0;
}

int TCPRenoConnection::onSelectiveAck()
{
    cout << "does not have a SACK Method!" << endl;
    return 0;
}

void TCPRenoConnection::adjustParameters()
{
    // to do
}

TCPRenoConnection::~TCPRenoConnection()
{

}
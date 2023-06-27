#include "../include/TCPNewRenoConnection.hpp"

class TCP;

TCPNewRenoConnection::TCPNewRenoConnection(int cwnd, int ssthresh, int rtt)
    : TCP(cwnd, ssthresh, rtt)
{   }

int TCPNewRenoConnection::onPacketLoss()
{
    return 0;
}

int TCPNewRenoConnection::onRTTUpdate()
{
    return 0;
}

int TCPNewRenoConnection::onSelectiveAck()
{
    return 0;
}

TCPNewRenoConnection::~TCPNewRenoConnection()
{
       
}
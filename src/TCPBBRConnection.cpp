#include "../include/TCPBBRConnection.hpp"

class TCP;

TCPBBRConnection::TCPBBRConnection(int cwnd, int ssthresh, int rtt)
    : TCP(cwnd, ssthresh, rtt)
{   }

int TCPBBRConnection::onPacketLoss()
{
    return 0;
}

int TCPBBRConnection::onRTTUpdate()
{
    return 0;
}

int TCPBBRConnection::onSelectiveAck()
{
    return 0;
}

void TCPBBRConnection::adjustParameters()
{
    // to do
}


TCPBBRConnection::~TCPBBRConnection()
{

}
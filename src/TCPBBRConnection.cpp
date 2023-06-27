#include "../include/TCPBBRConnection.hpp"

TCPBBRConnection::TCPBBRConnection(int cwnd, int ssthresh, int rtt)
    : TCP(cwnd, ssthresh, rtt)
{   }

int TCPBBRConnection::onPacketLoss()
{
    
}

int TCPBBRConnection::onRTTUpdate()
{

}

int TCPBBRConnection::onSelectiveAck()
{

}
#include "../include/TCPNewRenoConnection.hpp"

TCPNewRenoConnection::TCPNewRenoConnection(int cwnd, int ssthresh, int rtt)
    : TCP(cwnd, ssthresh, rtt)
{   }

int TCPNewRenoConnection::onPacketLoss()
{

}

int TCPNewRenoConnection::onRTTUpdate()
{

}

int TCPNewRenoConnection::onSelectiveAck()
{

}
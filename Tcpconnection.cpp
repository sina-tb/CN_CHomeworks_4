#include "Tcpconnection.hpp"

using namespace std;

TCPConnection::TCPConnection()
{
    cwnd = 1;
    ssthresh = 65535;
    rtt = 0;
}

int TCPConnection::SendData()
{

}

int TCPConnection::onPacketLoss()
{

}

int TCPConnection::onRTTUpdate()
{

}

int TCPConnection::onSelectiveAck()
{
    
}

int main()
{
    
}
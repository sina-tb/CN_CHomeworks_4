#include "../include/TCPRenoConnection.hpp"

#include <iostream>

using namespace std;


TCPRenoConnection::TCPRenoConnection(int cwnd, int ssthresh, int rtt) 
    : TCP(cwnd, ssthresh, rtt)
{   }

int TCPRenoConnection::onPacketLoss()
{

}

int TCPRenoConnection::onRTTUpdate()
{

}

int TCPRenoConnection::onSelectiveAck()
{
    cout << "does not have a SACK Method!" << endl;
}
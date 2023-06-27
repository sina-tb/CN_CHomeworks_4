#ifndef _TCP_RENO_CONNECTION_
#define _TCP_RENO_CONNECTION_

#include "TCP.hpp"

using namespace std;


class TCPRenoConnection : private TCP {
private:
    int _cwnd;       //Congestion window
    int _ssthresh;   // Slow start threshold
    int _rtt;        // ROund-trip time

public:

    // Reno algorithm
    TCPRenoConnection(int cwnd, int ssthresh, int rtt);
    vector<int> SendData();    
    int onPacketLoss(); 
    int onRTTUpdate();


    // New Reno algorithm function
    int onSelectiveAck();

    
};

#endif
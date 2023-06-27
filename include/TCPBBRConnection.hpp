#ifndef _TCP_BBR_CONNECTION_HPP_
#define _TCP_BBR_CONNECTION_HPP_

#include "TCP.hpp"

class TCPBBRConnection : private TCP {
private:
    int _cwnd;       //Congestion window
    int _ssthresh;   // Slow start threshold
    int _rtt;        // ROund-trip time

public:

    // Reno algorithm
    TCPBBRConnection(int cwnd, int ssthresh, int rtt);
    vector<int> SendData();    
    int onPacketLoss(); 
    int onRTTUpdate();


    // New Reno algorithm function
    int onSelectiveAck();

    
};

#endif
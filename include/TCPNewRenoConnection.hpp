#ifndef _TCP_NEW_RENO_CONNECTION_HPP_
#define _TCP_NEW_RENO_CONNECTION_HPP_

#include "TCP.hpp"

class TCPNewRenoConnection : public TCP {
private:
    int _cwnd;       //Congestion window
    int _ssthresh;   // Slow start threshold
    int _rtt;        // ROund-trip time

public:

    // Reno algorithm
    TCPNewRenoConnection(int cwnd, int ssthresh, int rtt);
    ~TCPNewRenoConnection();
    // vector<int> SendData();    
    int onPacketLoss(); 
    int onRTTUpdate();


    // New Reno algorithm function
    int onSelectiveAck();

};

#endif
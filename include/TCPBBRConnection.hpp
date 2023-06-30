#ifndef _TCP_BBR_CONNECTION_HPP_
#define _TCP_BBR_CONNECTION_HPP_

#include "TCP.hpp"

class TCPBBRConnection : public TCP {


public:

    // Reno algorithm
    TCPBBRConnection(int cwnd, int ssthresh, int rtt);
    ~TCPBBRConnection();

    // vector<int> SendData();    
    void adjustParameters();
    int onPacketLoss(); 
    int onRTTUpdate();


    // New Reno algorithm function
    int onSelectiveAck();

    
};

#endif
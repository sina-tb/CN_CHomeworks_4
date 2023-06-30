#ifndef _TCP_RENO_CONNECTION_
#define _TCP_RENO_CONNECTION_

#include "TCP.hpp"

#include <vector>

using namespace std;

class TCPRenoConnection : public TCP {

public:

    // Reno algorithm
    TCPRenoConnection(int cwnd, int ssthresh, int rtt);
    ~TCPRenoConnection();

    // vector<int> SendData();    
    void adjustParameters(const vector<int> sent);
    void adjustParameters(); 
    int onRTTUpdate();

    // New Reno algorithm function
    int onSelectiveAck();
    
};

#endif
#ifndef _TCP_NEW_RENO_CONNECTION_HPP_
#define _TCP_NEW_RENO_CONNECTION_HPP_

#include "TCP.hpp"

class TCPNewRenoConnection : public TCP {


public:

    // Reno algorithm
    TCPNewRenoConnection(int cwnd, int ssthresh, int rtt);
    ~TCPNewRenoConnection();

    void fastRetransmission();     

};

#endif
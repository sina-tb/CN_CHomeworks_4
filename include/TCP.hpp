#ifndef _TCP_HPP_
#define _TCP_HPP_

#include <vector>

using namespace std;


class TCP {
private:
    int _cwnd;       //Congestion window
    int _ssthresh;   // Slow start threshold
    int _rtt;        // ROund-trip time

public:

    TCP(int cwnd, int ssthresh, int rtt);
    virtual ~TCP() {}

    virtual vector<int> SendData();    
    virtual int onPacketLoss() = 0; 
    virtual int onRTTUpdate() = 0;
    // virtual void adjustParameters(){

    // New Reno algorithm function
    virtual int onSelectiveAck();
    
};

#endif

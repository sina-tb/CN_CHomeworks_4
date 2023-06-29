#ifndef _TCP_HPP_
#define _TCP_HPP_

#include <vector>

using namespace std;


class TCP {
private:
    int _cwnd;       //Congestion window
    int _ssthresh;   // Slow start threshold
    int _rtt;        // Round-trip time
    int _seqNum;     // Packet sequence number 

public:

    TCP(int cwnd, int ssthresh, int rtt);
    virtual ~TCP() {}

    virtual vector<int> SendData();    
    virtual vector<int> onPacketLoss(const vector<int> sent); 
    virtual int onRTTUpdate() = 0;
    virtual void adjustParameters() = 0;

    // New Reno algorithm function
    virtual int onSelectiveAck();
    
};

#endif

#ifndef _TCP_HPP_
#define _TCP_HPP_

#include <vector>

using namespace std;


class TCP {

protected:
    int _cwnd;       //Congestion window
    int _ssthresh;   // Slow start threshold
    int _rtt;        // Round-trip time
    int _seqNum;     // Packet sequence number
    vector<int> _lostPackets;
    int _total_sent{0};

public:

    bool _isOnRestransmitThisRTT;

    TCP(int cwnd, int ssthresh, int rtt);
    virtual ~TCP() {}

    virtual vector<int> SendData();    
    virtual vector<int> onPacketLoss(const vector<int> sent);
    virtual void fastRetransmission(){}
    virtual void adjustParameters(const vector<int> sent); 
    virtual void onRTTUpdate(int RTT);
    void printSessionDetails(const vector<int> sent);

};

#endif

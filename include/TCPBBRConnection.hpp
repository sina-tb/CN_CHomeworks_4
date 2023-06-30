<<<<<<< HEAD
#include <iostream> 
#include <vector> 
#include <algorithm> 
 
struct Packet { 
    double sendTime; 
    double arrivalTime; 
    double bandwidthEstimate; 
}; 
 
class BBR { 
public: 
=======
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

>>>>>>> 45ad50b5f2f0847ccf87a468abcc42c00423438f
    
    void simulate(); 
    void updateBandwidthEstimate();
    int start_simulation();
    void print_result();
    BBR(double st, double ps, double pd, double qd);


private: 
    double simulationTime = 10.0; 
    double packetSize = 1000.0; 
    double propagationDelay = 0.001; // Simulated propagation delay 
    double queueingDelay = 0.002;    // Simulated queueing delay 
    std::vector<Packet> packetsToSend; 
    std::vector<Packet> packetsReceived; 
}; 
 

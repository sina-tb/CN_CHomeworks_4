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
 

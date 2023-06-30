#include "../include/TCPBBRConnection.hpp"

BBR::BBR(double st, double ps, double pd, double qd)
{
    simulationTime = st;
    packetSize = ps;
    propagationDelay = pd;
    queueingDelay = qd;
}

void BBR::updateBandwidthEstimate() { 

    double maxArrivalTime = packetsReceived.back().arrivalTime; 
    double minArrivalTime = packetsReceived.front().arrivalTime; 
    double totalTime = maxArrivalTime - minArrivalTime; 
    double totalBytes = packetsReceived.size() * packetSize; 
    double estimatedBandwidth = totalBytes / totalTime; 

    for (auto& packet : packetsReceived)
        packet.bandwidthEstimate = estimatedBandwidth; 
} 

void BBR::simulate() { 
    double time = 0.0; 
    double bandwidth = 1.0;

    while (time < simulationTime) { 

        Packet packet; 
        packet.sendTime = time; 
        packet.bandwidthEstimate = bandwidth; 
        packetsToSend.push_back(packet); 

        double packetTransmissionTime = packetSize / bandwidth; 
        time += packetTransmissionTime; 

        double packetPropagationTime = propagationDelay + queueingDelay; 
        packet.arrivalTime = time + packetPropagationTime; 
        packetsReceived.push_back(packet); 

        updateBandwidthEstimate(); 

        time += packetPropagationTime; 
    } 

    print_result();

} 

void BBR::print_result() {
    
    std::cout << "Packet\tSend Time\tArrival Time\tBandwidth Estimate\n"; 
    for (int i = 0; i < packetsToSend.size(); ++i) { 
        std::cout << i << "\t" << packetsToSend[i].sendTime << "\t\t" 
                    << packetsReceived[i].arrivalTime << "\t\t" 
                    << packetsReceived[i].bandwidthEstimate << "\n"; 
    } 
}

int BBR::start_simulation() { 
    
    BBR bbr(10.0,1000.0,0.001,0.002); 
    bbr.simulate(); 
    return 0; 
}
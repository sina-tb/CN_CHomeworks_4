#include <chrono>
#include <algorithm>
#include <iostream>
#include <vector>

#define FAST_START false

using namespace std;

struct Packet
{
    int seq_num;
    int ack_num;
    double rtt;
    bool is_lost;
};

class TCPBBRConnection {

public:
    int total_rtt;
    int total_packets;
    TCPBBRConnection();
    void packet_sent();
    void lostPacketHandler(bool is_lost);
    void simulation(int num_packets, float packet_loss_rate);
    vector<Packet> create_packets(int num_packets, double packet_loss_rate);
    void examine_simulation(int num_packets, double packet_loss_rate);

private:
   
    float cwnd;
    float ssthresh;
    float rtt_;
    float min_rtt;

    chrono::time_point<chrono::steady_clock> round_start_time;
    chrono::time_point<chrono::steady_clock> next_send_time;
};




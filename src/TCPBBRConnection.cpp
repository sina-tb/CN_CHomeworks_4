#include <chrono>
#include <algorithm>
#include <iostream>
#include <vector>
#include "../include/TCPBBRConnection.hpp"

#define FAST_START false

using namespace std;


TCPBBRConnection:: TCPBBRConnection()
{
    cwnd = 80;
    ssthresh = INT_MAX;
    rtt_ = 1;
    min_rtt = 0;
    round_start_time = chrono::steady_clock::now();
    next_send_time = round_start_time + chrono::microseconds(
            static_cast<int>(cwnd * 1000000.0 / rtt_));
}

void TCPBBRConnection::packet_sent()
{
    if (chrono::steady_clock::now() >= next_send_time) 
        next_send_time = chrono::steady_clock::now() + chrono::microseconds(static_cast<int>(cwnd * 1000000.0 / rtt_));
} 


void TCPBBRConnection::handle_ack_packet(bool is_lost)
{
    if(!is_lost)
    {
        auto now = chrono::steady_clock::now();
        float rtt = chrono::duration_cast<chrono::microseconds>(now - round_start_time).count() / 1000.0;
        
        if (min_rtt == 0) 
        {
            min_rtt = rtt;
        } 

        else 
        {
            min_rtt = min(min_rtt, rtt);
        }

        float bytes_acked = cwnd * rtt / min_rtt;
        float k = pow(cwnd, 3.0 / 4.0) / sqrt(bytes_acked * 0.9 + cwnd * cwnd * 0.1);
        cwnd += k;
        cwnd = min(cwnd, ssthresh);
        round_start_time = now;
    }
    else
    {
        cwnd *= 0.5;
    }
}

vector<Packet> TCPBBRConnection::create_packets(int num_packets, double packet_loss_rate) 
{
    vector<Packet> packets;

    for (int i = 0; i < num_packets; i++) 
    {
        Packet packet;
        packet.seq_num = i;
        packet.ack_num = -1;
        packet.is_lost = false;
        packets.push_back(packet);
    }

    // packet loss
    for (int i = 1; i < num_packets; i++) 
    {
        double rand_num = (double) rand() / RAND_MAX;
        if (rand_num < packet_loss_rate)
            packets[i].is_lost = true;
    }

    // rtt a random number between 100 and 150
    for (int i = 0; i < num_packets; i++) 
        packets[i].rtt = 100 + (double) rand() / RAND_MAX * 50;
    
    return packets;
}

void TCPBBRConnection::simulation(int num_packets, float packet_loss_rate)
{
    // create packets
    vector<Packet> packets = create_packets(num_packets, packet_loss_rate);

    // send packets
    for (int i = 0; i < num_packets; ++i) {
        packet_sent();
        Packet packet = packets[i];
        if (packet.is_lost)
            cout <<"packet number" << packet.seq_num << "is lost"<<endl;
        cout << "the window size: " <<  int(cwnd) << endl;
        handle_ack_packet(packet.is_lost);
    }

    
}

void TCPBBRConnection::examine_simulation() {
    
    auto start = chrono::high_resolution_clock::now();
    srand(time(NULL));
    simulation(200, 0.2);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
 
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}

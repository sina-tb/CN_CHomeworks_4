


using namespace std;


class TCPConnection {
private:
    int cwnd;       //Congestion window
    int ssthresh;   // Slow start threshold
    int rtt;        // ROund-trip time

public:

    // Reno algorithm
    TCPConnection();
    int SendData();    
    int onPacketLoss(); 
    int onRTTUpdate();


    // New Reno algorithm function
    int onSelectiveAck();

    //BBR algorithm
    
};
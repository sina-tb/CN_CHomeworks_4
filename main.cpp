#include "./include/TCP.hpp"
#include "./include/TCP.hpp"
#include "./include/TCPRenoConnection.hpp"
#include "./include/TCPNewRenoConnection.hpp"
#include "./include/TCPBBRConnection.hpp"

#include <iostream>

using namespace std;

int main()
{
    TCPRenoConnection* T2 = new TCPRenoConnection(1, INT32_MAX, 200);
    TCPNewRenoConnection* T3 = new TCPNewRenoConnection(1, INT32_MAX, 200);
    T2->onRTTUpdate(8000);
    srand(time(0));
    T3->onRTTUpdate(8000);
    // TCPNewRenoConnection* T3 = new TCPNewRenoConnection(20, 200, 200);
    
    
    //examine BBR protocol
    TCPBBRConnection* T4 = new TCPBBRConnection();
    T4->examine_simulation(200, 0.1);
    
    
    
    
    return 0;
}
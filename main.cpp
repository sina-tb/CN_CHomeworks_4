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
    for(int i = 0; i < 20; i++)
    {
        cout << "iteration: " << i 
            << ":" << endl;
        if(T2->_isOnRestransmitThisRTT)
        {
            T2->fastRetransmission();
        }
        else
        {
            T2->SendData();
            T2->adjustParameters();
        }
            
    }
    // TCPNewRenoConnection* T3 = new TCPNewRenoConnection(20, 200, 200);
    // TCPBBRConnection* T4 = new TCPBBRConnection(20, 200, 200);
    return 0;
}
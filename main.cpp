#include "./include/TCP.hpp"
#include "./include/TCP.hpp"
#include "./include/TCPRenoConnection.hpp"
#include "./include/TCPNewRenoConnection.hpp"
#include "./include/TCPBBRConnection.hpp"

#include <iostream>

using namespace std;

int main()
{
    TCPRenoConnection* T2 = new TCPRenoConnection(1, __INT32_MAX__, 200);
    for(int i = 0; i < 20; i++)
    {
        cout << "iteration: " << i 
            << ":" << endl;
        T2->SendData();
    }
    // TCPNewRenoConnection* T3 = new TCPNewRenoConnection(20, 200, 200);
    // TCPBBRConnection* T4 = new TCPBBRConnection(20, 200, 200);
    return 0;
}
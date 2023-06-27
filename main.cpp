#include "./include/TCP.hpp"
#include "./include/TCP.hpp"
#include "./include/TCPRenoConnection.hpp"
#include "./include/TCPNewRenoConnection.hpp"
#include "./include/TCPBBRConnection.hpp"

int main()
{
    TCPRenoConnection* T2 = new TCPRenoConnection(20, 200, 200);
    TCPNewRenoConnection* T3 = new TCPNewRenoConnection(20, 200, 200);
    TCPBBRConnection* T4 = new TCPBBRConnection(20, 200, 200);
    return 0;
}
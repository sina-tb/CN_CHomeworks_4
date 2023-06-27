#include "../include/TCP.hpp"

TCP::TCP(int cwnd, int ssthresh, int rtt) :
    _cwnd(cwnd),
    _ssthresh(ssthresh),
    _rtt(rtt)
{   }

/// @brief 
// Will be used for all of the tcp extensions if not needed to be implemented differently 
/// @return 
vector<int> TCP::SendData()
{

}
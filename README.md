# CN_CHomeworks_4
**Difference between flow control and congestion control:**
* Flow Control:
Flow control is a mechanism used to manage the rate of data transmission between a sender and a receiver to prevent overwhelming the receiver's buffer or exceeding its capacity. It ensures that the sender does not transmit data faster than the receiver can handle. It works by exchanging the control messages, such as ACK (acknowledgment) between the sender and receiver. These messages allow the receiver to inform the sender about the amount of data it can accept or the current state of its buffer.

* Congestion Control:
Congestion control focuses on avoiding or controlling network congestion by regulating the flow of data within a network. Congestion occurs when there is more data being transmitted into a network than it can handle, leading to time outs, increased delays, packet loss, and reduced network performance. It involves various algorithms and techniques to detect and respond to network congestion. These techniques may involve monitoring network traffic, adjusting transmission rates, or controlling the amount of data sent by individual hosts.

In summary, flow control is concerned with endpoints while congestion control is concerned with the network.

**TCP NEW RENO:**

before we explain NEW RENO it is necessary to explain TCP RENO:

TCP Reno is a congestion control algorithm used in the Transmission Control Protocol (TCP), which is responsible for reliable data transmission over the internet. Its main goal is to prevent network congestion and ensure fair sharing of available bandwidth among different TCP connections.
When using TCP Reno, each TCP connection maintains a congestion window (cwnd) that determines the number of packets it can send without causing congestion. Initially, the cwnd is small, allowing only a few packets to be sent. In slow start mode, cwnd grows exponentially. As the connection progresses and no congestion is detected, the cwnd increases, allowing more packets to be sent.
TCP Reno uses a mechanism called Additive Increase Multiplicative Decrease (AIMD) to adjust the cwnd. During the additive increase phase, for every successful acknowledgment received, the cwnd is increased by a small fixed value. This gradual increase ensures that the network capacity is utilized effectively.
If congestion is detected, typically by packet loss or an indication from the network, TCP Reno enters the multiplicative decrease phase. The cwnd is then reduced significantly to avoid further congestion. After congestion occurs, TCP Reno reduces the cwnd by half to be conservative and provides a fairer chance for other connections sharing the same network resources.
Once the congestion is detected, TCP Reno enters a recovery phase known as Fast Retransmit and Fast Recovery. Instead of waiting for a timeout, which would result in slower retransmission, after 3 duplicate ACKs, TCP Reno assumes that a lost packet occurred and retransmits it immediately. This avoids unnecessary delays and improves performance.
TCP Reno continues the AIMD cycle, increasing the cwnd during normal operation and decreasing it upon congestion. This helps to maintain a balance between efficient utilization of the network resources and avoiding congestion.

In summary, TCP Reno is a congestion control algorithm that dynamically adjusts the congestion window of TCP connections based on network conditions. It employs additive increase for normal operation, multiplicative decrease upon congestion, and fast retransmit/fast recovery mechanisms for efficient packet retransmission.

*TCP NEW RENO*:

New Reno is a TCP  congestion control algorithm, which is an enhancement of the original Reno congestion control algorithm.
The Reno congestion control algorithm is widely used in TCP implementations. It uses a combination of slow start and congestion avoidance mechanisms to regulate the sending rate and react to network congestion.
The New Reno protocol introduces a modification to the recovery phase of Reno to improve its handling of multiple packet losses within a single window of data. In the original Reno, when a segment loss is detected, the sender reduces its congestion window (cwnd) and enters a fast recovery phase where it retransmits the lost packet without reducing the sending rate further. However, if subsequent packet losses occur within the same window, Reno unnecessarily reduces the sending rate to a more conservative level.

New Reno by using SACK(selected acks) method improves upon this behavior by allowing the sender to retransmit multiple lost packets within the same window without reducing the cwnd. It avoids unnecessary reductions in the sending rate when there are consecutive packet losses within the same window, thereby maintaining a higher throughput compared to the original Reno algorithm.
The New Reno protocol retains the key components of the Reno congestion control algorithm, including slow start, congestion avoidance, and fast recovery. It provides better efficiency and fairness in scenarios with multiple packet losses within a single window, making it suitable for modern networks with higher speeds.

**BBR:**



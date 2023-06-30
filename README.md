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

The BBR (Bottleneck Bandwidth and Round-Trip Time) protocol is a congestion control algorithm designed for TCP connections. It was developed by Google and introduced as a replacement for traditional TCP congestion control algorithms, such as Reno or Cubic. BBR aims to optimize network performance by dynamically adjusting the sending rate based on estimates of the available bandwidth and RTT.

The key features and goals of the BBR protocol include:

* Bandwidth Estimation:
BBR focuses on estimating the available bandwidth of the network path. It does so by probing the network with controlled sending rates and measuring the throughput achieved without causing excessive queuing delay.

* RTT Estimation:
BBR estimates the RTT of the network path. It uses both the minimum RTT and the time when a packet exits the network (sending timestamp) to calculate the RTT. This RTT estimation is crucial for determining the pacing rate and reacting to congestion events.

* Model of the Network Bottleneck:
BBR views the network as a bottleneck link that limits the transmission rate. It focuses on estimating the maximum capacity of this bottleneck link to optimize congestion control.

* Pacing and Congestion Window Management:
BBR combines both pacing and congestion window management to control the sending rate. Pacing regulates the rate at which packets are sent to match the available bandwidth, while the cwnd regulates the amount of data in flight. BBR adjusts the pacing rate and cwnd based on the estimated available bandwidth and RTT.

* Congestion Signaling:
BBR relies on two signals to detect congestion: packet loss and increased queuing delay. Packet loss is considered a clear indicator of congestion, and BBR reduces the cwnd upon detecting it. Increased queuing delay is an early sign of congestion, and BBR responds by reducing the sending rate to avoid further congestion.

* Congestion Recovery:
When BBR detects congestion, it enters a congestion recovery phase. During this phase, BBR reduces the cwnd and limits the sending rate to alleviate congestion. It gradually ramps up the sending rate again after congestion is relieved, taking a cautious approach to avoid triggering further congestion.

BBR has been shown to provide significant performance improvements, particularly in networks with large bandwidth-delay products (BDP) and high-speed, long-distance connections. It is widely adopted and supported by various TCP implementations, and it is commonly used by major internet services to optimize network performance and reduce latency.

**difference of RENO, NEW RENO, BBR:**
Reno, New Reno, and BBR are all TCP congestion control algorithms, but they have distinct characteristics and goals. Here's a comparison of the three protocols:

* Reno:

Reno is one of the earliest and most widely used TCP congestion control algorithms.
It uses a combination of slow start, congestion avoidance, and fast recovery mechanisms.
Upon detecting packet loss, Reno reduces its cwnd and enters a fast recovery phase where it retransmits the lost packet without reducing the sending rate further.
Reno's behavior is relatively conservative and aims to maintain stability and fairness in the network.
It performs well in moderate network conditions but can experience performance degradation in high-speed or high-latency networks with large bandwidth-delay product (BDP).

* New Reno:

New Reno is an enhancement of the original Reno congestion control algorithm.
It addresses the limitation of Reno's fast recovery phase by allowing multiple packet losses within a single window without further reducing the cwnd(using SACK).
When multiple packet losses occur within the same window, New Reno avoids unnecessary reductions in the sending rate, leading to higher throughput compared to Reno.
New Reno retains the basic components of Reno, including slow start, congestion avoidance, and fast recovery, while improving its performance in scenarios with multiple packet losses.

* BBR:

BBR is a relatively newer congestion control algorithm developed by Google.
It takes a different approach compared to Reno and New Reno by focusing on estimating the available bandwidth and RTT of the network path.
BBR views the network as a bottleneck link and aims to estimate the maximum capacity of this bottleneck to optimize congestion control.
It uses advanced algorithms to probe the network and measure the throughput achieved without causing excessive queuing delay.
BBR dynamically adjusts the sending rate based on the estimated available bandwidth and RTT to maximize network throughput and minimize queuing delay.
It adapts well to varying network conditions and is particularly effective in high-speed or high-latency networks with large BDP.

In summary, Reno and New Reno are traditional congestion control algorithms that focus on stability, fairness, and moderate network conditions. New Reno improves upon Reno's handling of multiple packet losses within a window. BBR, on the other hand, is a more modern and innovative congestion control algorithm that prioritizes maximizing throughput and minimizing queuing delay by estimating available bandwidth and RTT. BBR is well-suited for high-speed and high-latency networks.


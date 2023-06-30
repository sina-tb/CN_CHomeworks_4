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

**Compare RENO, NEW RENO, and BBR in the same situation:**

The choice of the "best" congestion control protocol among Reno, New Reno, and BBR depends on the specific network conditions, requirements, and objectives. Each protocol has its strengths and considerations. Here are some factors to consider when selecting a congestion control protocol:

* Network Characteristics:

Reno and New Reno: These algorithms are generally suitable for traditional networks with moderate speeds and latencies.
BBR: BBR is designed to perform well in high-speed networks and networks with large bandwidth-delay product (BDP).
Throughput and Latency Optimization:

BBR: BBR aims to maximize throughput and minimize queuing delay by estimating available bandwidth and RTT.
Reno and New Reno: These protocols focus on stability, fairness, and moderate throughput.

* Network Stability and Fairness:

Reno and New Reno: These protocols are designed with stability and fairness in mind, making them well-suited for traditional network environments.

* Compatibility:

Reno and New Reno: These algorithms are widely supported in most TCP implementations and are the default congestion control choices in many systems.
BBR: While BBR is gaining popularity, its adoption might not be as widespread as Reno and New Reno in all network devices and software.

* Network Type:

If you have a high-speed or high-latency network, BBR might provide better performance due to its focus on estimating available bandwidth and RTT.
For traditional networks with moderate speeds and latencies, Reno or New Reno can be suitable choices.
Ultimately, the "best" congestion control protocol depends on the specific requirements and network conditions. It is common to see a combination of protocols being used in different parts of the internet infrastructure to optimize performance and accommodate diverse network scenarios.






**Other congestion control algorithms:**

While Reno, New Reno, and BBR are widely used and well-regarded congestion control protocols, there are other algorithms that have been developed to address specific challenges or provide improvements in certain network scenarios. One such example is the TCP CUBIC congestion control algorithm.

*TCP CUBIC*:

TCP CUBIC is a congestion control algorithm that aims to optimize performance in high-speed, long-distance networks. It is designed to address the limitations of traditional congestion control algorithms, including Reno and New Reno, in scenarios where bandwidth-delay product (BDP) is large.

CUBIC uses a different approach to pacing and congestion window management compared to Reno-based algorithms. Instead of linear growth during slow start and additive increase during congestion avoidance, CUBIC adopts a cubic growth function based on the concept of TCP-friendly window. It maintains a model of the network's congestion window over time and adjusts the sending rate accordingly.

The key characteristics of TCP CUBIC include:

* Improved Congestion Window Growth:
CUBIC employs a cubic growth function to determine the congestion window size. It allows for a faster initial window increase and more aggressive window growth during congestion avoidance.

* RTT-based Congestion Control:
CUBIC takes into account the round-trip time (RTT) and the number of packet losses to estimate the congestion level. It adjusts the congestion window based on this information to achieve a fair share of the available bandwidth.

* Scalability and Fairness:
TCP CUBIC is designed to scale well in high-speed networks and handle large bandwidth-delay products. It aims to achieve fairness among multiple competing TCP connections.

TCP CUBIC has been widely adopted and is supported in various TCP implementations. It has demonstrated improved performance in high-speed and long-distance network environments, making it a viable alternative to Reno, New Reno, and BBR in those scenarios.
It's important to note that the choice of congestion control protocol depends on the specific network characteristics and requirements. Different algorithms may be more suitable for different scenarios, and the "best" protocol will vary accordingly.

another example that has gained attention and shown promising results is the Multipath TCP (MPTCP) protocol.

*Multipath TCP (MPTCP):*

MPTCP is an extension of the traditional TCP protocol that allows for the simultaneous use of multiple network paths in a single TCP connection. It is designed to enhance performance, reliability, and resilience by leveraging multiple paths, such as multiple network interfaces or different network technologies.

Key features of MPTCP include:

* Multi-Path Capability:
MPTCP enables a TCP connection to utilize multiple paths concurrently. This allows for increased throughput by spreading the data across available paths.

* Dynamic Path Selection:
MPTCP can dynamically select and utilize the most efficient and available path based on network conditions. It can adapt to changes in path characteristics, such as congestion or link failures, to maintain optimal performance.

* Resilience and Fault Tolerance:
With its multi-path capability, MPTCP can recover from link failures or disruptions by seamlessly switching to alternative paths, ensuring data delivery and improving reliability.

* Load Balancing and Congestion Control:
MPTCP intelligently distributes data across multiple paths, optimizing load balancing and improving overall network utilization. It also includes congestion control mechanisms to avoid overwhelming any individual path.

MPTCP has been shown to provide performance benefits in scenarios where multiple network paths are available, such as devices with multiple interfaces or networks with diverse connectivity options. It offers advantages like improved throughput, enhanced fault tolerance, and better utilization of available network resources.
It's important to note that MPTCP requires support from both the client and server endpoints, as well as the network infrastructure. While MPTCP can offer benefits in certain scenarios, its adoption and deployment may be limited by compatibility and infrastructure considerations.

Multipath TCP (MPTCP) offers distinct advantages over Reno, New Reno, and BBR congestion control algorithms in certain network scenarios. Here are some aspects where MPTCP provides benefits:

* Increased Throughput and Resource Utilization:
MPTCP enables the simultaneous use of multiple network paths in a single TCP connection. This allows for increased throughput by aggregating the bandwidth of multiple paths. Unlike Reno, New Reno, and BBR, which operate on a single path, MPTCP leverages the available network resources more effectively.

* Improved Resilience and Fault Tolerance:
With its ability to utilize multiple paths, MPTCP enhances network resilience and fault tolerance. If one path experiences congestion or fails, MPTCP can seamlessly switch the traffic to alternative paths, ensuring continuous data transmission. This fault tolerance capability is particularly useful in environments with unreliable or unstable network connections.

* Dynamic Path Selection:
MPTCP can dynamically select and utilize the most efficient path based on network conditions. It considers factors such as congestion, delay, and available bandwidth to optimize performance. In contrast, Reno, New Reno, and BBR typically operate on a single path and do not have the flexibility to adapt to changing network conditions.

* Load Balancing and Congestion Control:
MPTCP intelligently distributes data across multiple paths, achieving load balancing and optimizing the utilization of available network resources. It can balance the traffic based on path characteristics, avoiding congestion on any individual path. In contrast, Reno, New Reno, and BBR focus on congestion control within a single path.

* Path Diversity:
MPTCP allows for the utilization of diverse network paths, such as multiple interfaces or different network technologies. This can be advantageous in scenarios where different paths offer varying characteristics, such as bandwidth, latency, or reliability.

As said before MPTCP requires support from both the client and server endpoints, as well as the network infrastructure. While MPTCP offers benefits in specific network scenarios, its adoption and deployment may be limited by compatibility and infrastructure considerations. Therefore, careful consideration should be given to the network requirements and feasibility of MPTCP deployment before choosing it over other congestion control algorithms.

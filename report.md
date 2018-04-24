# hw7-mlpotter
hw7-mlpotter created by GitHub Classroom
<br /> 
## 1. 
<br /> O(M^2 * L^2)

Iterate through all members and compare each of the members groups to each other. If the members share a group_id then create a bidirectional edge between the two members and break from the loop which compares group_ids since only 1 edge may exist between two members.

Time to build member graph 6.31789

## 2.

<br /> Time to find path to member 0.0098209
<br /> Time to find path to member 0.0110455
<br /> Time to find path to member 0.0120101

## 3. 
<br />//commented out
<br /> 	p2. 
Command being timed: "./p2_main"
<br />         User time (seconds): 5.04
<br />         System time (seconds): 0.17
<br />         Percent of CPU this job got: 99%
<br />         Elapsed (wall clock) time (h:mm:ss or m:ss): 0:05.22
<br />         Average shared text size (kbytes): 0
<br />         Average unshared data size (kbytes): 0
<br />         Average stack size (kbytes): 0
<br />         Average total size (kbytes): 0
<br />         Maximum resident set size (kbytes): 126740
<br />         Average resident set size (kbytes): 0
<br />         Major (requiring I/O) page faults: 0
<br />         Minor (reclaiming a frame) page faults: 31142
<br />         Voluntary context switches: 4
<br />         Involuntary context switches: 44
<br />         Swaps: 0
<br />         File system inputs: 52784
<br />         File system outputs: 0
<br />         Socket messages sent: 0
<br />         Socket messages received: 0
<br />         Signals delivered: 0
<br />         Page size (bytes): 4096
<br />         Exit status: 0

<br />    //not commented
<br /> Command being timed: "./p2_main"
<br />         User time (seconds): 4.88
<br />         System time (seconds): 0.15
<br />         Percent of CPU this job got: 99%
<br />         Elapsed (wall clock) time (h:mm:ss or m:ss): 0:05.05
<br />         Average shared text size (kbytes): 0
<br />         Average unshared data size (kbytes): 0
<br />         Average stack size (kbytes): 0
<br />         Average total size (kbytes): 0
<br />         Maximum resident set size (kbytes): 126860
<br />         Average resident set size (kbytes): 0
<br />         Major (requiring I/O) page faults: 0
<br />         Minor (reclaiming a frame) page faults: 31160
<br />         Voluntary context switches: 3
<br />         Involuntary context switches: 11
<br />         Swaps: 0
<br />         File system inputs: 7400
<br />         File system outputs: 0
<br />         Socket messages sent: 0
<br />         Socket messages received: 0
<br />         Signals delivered: 0
<br />         Page size (bytes): 4096
<br />         Exit status: 0

<br /> 126860 - 126740 = 120 kbytes

<br /> 	p3.
<br /> //commented out
<br /> Command being timed: "./p3_main"
<br />         User time (seconds): 5.36
<br />         System time (seconds): 0.24
<br />         Percent of CPU this job got: 99%
<br />         Elapsed (wall clock) time (h:mm:ss or m:ss): 0:05.61
<br />         Average shared text size (kbytes): 0
<br />         Average unshared data size (kbytes): 0
<br />         Average stack size (kbytes): 0
<br />         Average total size (kbytes): 0
<br />         Maximum resident set size (kbytes): 126816
<br />         Average resident set size (kbytes): 0
<br />         Major (requiring I/O) page faults: 0
<br />         Minor (reclaiming a frame) page faults: 31144
<br />         Voluntary context switches: 1
<br />         Involuntary context switches: 101
<br />         Swaps: 0
<br />         File system inputs: 0
<br />         File system outputs: 0
<br />         Socket messages sent: 0
<br />         Socket messages received: 0
<br />         Signals delivered: 0
<br />         Page size (bytes): 4096
<br />         Exit status: 0

<br /> Command being timed: "./p3_main"
<br />         User time (seconds): 5.04
<br />         System time (seconds): 0.12
<br />         Percent of CPU this job got: 99%
<br />         Elapsed (wall clock) time (h:mm:ss or m:ss): 0:05.18
<br />         Average shared text size (kbytes): 0
<br />         Average unshared data size (kbytes): 0
<br />         Average stack size (kbytes): 0
<br />         Average total size (kbytes): 0
<br />         Maximum resident set size (kbytes): 126784
<br />         Average resident set size (kbytes): 0
<br />         Major (requiring I/O) page faults: 0
<br />         Minor (reclaiming a frame) page faults: 31143
<br />         Voluntary context switches: 1
<br />         Involuntary context switches: 65
<br />         Swaps: 0
<br />         File system inputs: 0
<br />         File system outputs: 0
<br />         Socket messages sent: 0
<br />         Socket messages received: 0
<br />         Signals delivered: 0
<br />         Page size (bytes): 4096
<br />         Exit status: 0

<br /> 126816 – 126784 = 32 kbytes


IDDFS mimics the memory usage of DFS while obtaining the optimal solution by searching in a similar pattern to BFS. Therefore, the IDDFS uses substantially less memory, as the DFS only maintains the current path being traversed in memory and the BFS maintains a queue to store all the nodes at the current level. Therefore, DFS memory consumption is much smaller than BFS memory consumption.
BFS space complexity is O(|V|) compared to DFS space complexity of O(h) , where h is the maximal depth of the tree. 
IDDFS has the same space complexity as DFS.

## 4.
<br /> Scott Heiferman <- Pat Finegan <- djouffyo <- marian <- Denise Yap <- janezeng <- kirstin_leifels <- vjm89 <- hhpierce <- Matt Meeker
<br /> 
Time to generate MST 0.608689

# hw7-mlpotter
hw7-mlpotter created by GitHub Classroom
<br /> 
##1.
O(M^2 * L^2)

Iterate through all members and compare each of the members groups to each other. If the members share a group_id then create a bidirectional edge between the two members and break from the loop which compares group_ids since only 1 edge may exist between two members.

Time to build member graph 6.31789

##2.

<br /> Time to find path to member 0.0098209
<br /> Time to find path to member 0.0110455
<br /> Time to find path to member 0.0120101

##3. 
<br />//commented out
	p2. 
Command being timed: "./p2_main"
        User time (seconds): 5.04
        System time (seconds): 0.17
        Percent of CPU this job got: 99%
        Elapsed (wall clock) time (h:mm:ss or m:ss): 0:05.22
        Average shared text size (kbytes): 0
        Average unshared data size (kbytes): 0
        Average stack size (kbytes): 0
        Average total size (kbytes): 0
        Maximum resident set size (kbytes): 126740
        Average resident set size (kbytes): 0
        Major (requiring I/O) page faults: 0
        Minor (reclaiming a frame) page faults: 31142
        Voluntary context switches: 4
        Involuntary context switches: 44
        Swaps: 0
        File system inputs: 52784
        File system outputs: 0
        Socket messages sent: 0
        Socket messages received: 0
        Signals delivered: 0
        Page size (bytes): 4096
        Exit status: 0

   //not commented
Command being timed: "./p2_main"
        User time (seconds): 4.88
        System time (seconds): 0.15
        Percent of CPU this job got: 99%
        Elapsed (wall clock) time (h:mm:ss or m:ss): 0:05.05
        Average shared text size (kbytes): 0
        Average unshared data size (kbytes): 0
        Average stack size (kbytes): 0
        Average total size (kbytes): 0
        Maximum resident set size (kbytes): 126860
        Average resident set size (kbytes): 0
        Major (requiring I/O) page faults: 0
        Minor (reclaiming a frame) page faults: 31160
        Voluntary context switches: 3
        Involuntary context switches: 11
        Swaps: 0
        File system inputs: 7400
        File system outputs: 0
        Socket messages sent: 0
        Socket messages received: 0
        Signals delivered: 0
        Page size (bytes): 4096
        Exit status: 0

126860 - 126740 = 120 kbytes

	p3.
//commented out
Command being timed: "./p3_main"
        User time (seconds): 5.36
        System time (seconds): 0.24
        Percent of CPU this job got: 99%
        Elapsed (wall clock) time (h:mm:ss or m:ss): 0:05.61
        Average shared text size (kbytes): 0
        Average unshared data size (kbytes): 0
        Average stack size (kbytes): 0
        Average total size (kbytes): 0
        Maximum resident set size (kbytes): 126816
        Average resident set size (kbytes): 0
        Major (requiring I/O) page faults: 0
        Minor (reclaiming a frame) page faults: 31144
        Voluntary context switches: 1
        Involuntary context switches: 101
        Swaps: 0
        File system inputs: 0
        File system outputs: 0
        Socket messages sent: 0
        Socket messages received: 0
        Signals delivered: 0
        Page size (bytes): 4096
        Exit status: 0

Command being timed: "./p3_main"
        User time (seconds): 5.04
        System time (seconds): 0.12
        Percent of CPU this job got: 99%
        Elapsed (wall clock) time (h:mm:ss or m:ss): 0:05.18
        Average shared text size (kbytes): 0
        Average unshared data size (kbytes): 0
        Average stack size (kbytes): 0
        Average total size (kbytes): 0
        Maximum resident set size (kbytes): 126784
        Average resident set size (kbytes): 0
        Major (requiring I/O) page faults: 0
        Minor (reclaiming a frame) page faults: 31143
        Voluntary context switches: 1
        Involuntary context switches: 65
        Swaps: 0
        File system inputs: 0
        File system outputs: 0
        Socket messages sent: 0
        Socket messages received: 0
        Signals delivered: 0
        Page size (bytes): 4096
        Exit status: 0

126816 – 126784 = 32 kbytes


IDDFS mimics the memory usage of DFS while obtaining the optimal solution by searching in a similar pattern to BFS. Therefore, the IDDFS uses substantially less memory, as the DFS only maintains the current path being traversed in memory and the BFS maintains a queue to store all the nodes at the current level. Therefore, DFS memory consumption is much smaller than BFS memory consumption.
BFS space complexity is O(|V|) compared to DFS space complexity of O(h) , where h is the maximal depth of the tree. 
IDDFS has the same space complexity as DFS.

## 4.
Scott Heiferman <- Pat Finegan <- djouffyo <- marian <- Denise Yap <- janezeng <- kirstin_leifels <- vjm89 <- hhpierce <- Matt Meeker

Time to generate MST 0.608689

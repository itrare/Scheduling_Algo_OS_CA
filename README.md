# Scheduling Algorithms
This repository contains SJF preemptive scheduling algorithm and Longest Time Remaining First Alogorithm.

# Longest Remaining Time First
Example :- 

      0_____1_____2_____3_____4_____5_____6_____7_____8_____9_____10____11____12____13____14____15____16
      | P2  | P1  | P2  | P4  | P4  | P5  | P4  | P5  | P3  | P4  | P5  | P1  | P2  | P3  | P4  | P5  |
      |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|

      PROCESS ID       ARRIVAL TIME    BURST TIME      COMPLETION TIME  TAT            WT
      1                0               2               12               12             10
      2                0               3               13               13             10
      3                2               2               14               12             10
      4                3               5               15               12             7
      5                4               4               16               12             8
      Average TAT 12.2
      Average WT  9


# Sortest Job First
    0__1__2__3__4__5__6__7__8__9__10_11_12_13_14_15_16
    |P1|P1|P2|P2|P3|P2|P2|P4|P4|P4|P4|P1|P1|P1|P1|P1|
    |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|

    PID             BT              AT              CT              TAT             WT
    1               7               0               16              16              9
    2               4               2               7               5               1
    3               1               4               5               1               0
    4               4               5               11              6               2

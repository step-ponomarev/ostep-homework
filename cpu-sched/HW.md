1) Compute the response time and turnaround time when running three jobs of length 200 with the SJF and FIFO schedulers
#### FIFO | SJF
Job | Response | Turnaround |
----|---|------|
Job 1|0|200|
Job 2|200|400|
Job 3|400|600|


2) Now do the same but with jobs of different lengths: 100, 200, and 300.
#### FIFO | SJF
Job | Response | Turnaround |
----|----------|------------|
Job 1| 0        | 100       |
Job 2| 100      | 300       |
Job 3| 300      | 600       |

3) Now do the same, but also with the RR scheduler and a time-slice of 1.

Job | Response | Turnaround|
----|----------|-----------|
Job 1| 0       | 298       |
Job 2| 1       | 499       |
Job 3| 2       | 600       |

4) For what types of workloads does SJF deliver the same turnaround times as FIFO?

A:
When the order goes from the shortest job to the largest.

5) For what types of work load sand quantum lengths does SJF deliver the same response times as RR?

A:
When the length of the jobs is the same as the quantum length.

6) What happens to response time with SJF as job lengths increase? Can you use the simulator to demonstrate the trend?

A:
If, before the shortest job increases, it is not the shortest, it will increase the response time of the previous shortest job and decrease the response time of the second shortest.

Example:
```sh
prompt> python3 scheduler.py -p SJF -l 20,20 -c
```

```sh
prompt> python3 scheduler.py -p SJF -l 21,20 -c
```

7) What happens to response time with RR as quantum lengths increase? Can you write an equation that gives the worst-case response time, given N jobs?

A:
It increases responce time of each job except first.
RT_N = (Qt * N-1)
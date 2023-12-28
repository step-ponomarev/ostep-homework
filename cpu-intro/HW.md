## Q1
Run `process-run.py` witht the following flags: `-l 5:100,5:100`. What should the CPU utilization be (e.g., the percent of time the CPU is in use?) Why do you know this? Use the -c and -p flags to see if you were right.

### A:
First, the process with PID=0 runs 5 instructions(PID=1 in READY state) and then goes to the DONE state. 
Afterward, the process with PID=1 starts and also runs 5 instructions (PID=0 in DONE state).
CPU utilization will be 100%

## Q2
Now run with these flags: ./process-run.py -l 4:100,1:0. These flags specify one process with 4 instructions (all to use the CPU), and one that simply issues an I/O and waits for it to be done. How long does it take to complete both processes? Use -c and -p to find out if you were right

### A:
./process-run.py -l 4:100,1:0
First, the CPU will complete 4 instructions for PID=0, then it goes to the DONE state. Afterward, PID=1 starts and progresses through RUN:io -> BLOCKED x5 by default -> DONE. So, I think it takes 4 + 5 + 2 = 11 'CPU ticks'

## Q3
Switch the order of the processes: -l 1:0,4:100. What happens now? Does switching the order matter? Why? (As always, use -c and -p to see if you were right)

### A:
Process 0 will start and immediately be blocked on the second tick. 
At this time, process 1 starts, works, and executes 4 instructions before it is done. When process 1 finishes, process 0 will wait for 1 tick and then also go to the DONE state. 
The order of switching matters: now it takes 7 ticks!

## Q4
We’ll now explore some of the other flags. One important flag is -S, 
which determines how the system reacts when a process is- sues an I/O. 
With the flag set to SWITCH ON END, the system will NOT switch to another process while one is doing I/O, in- stead waiting until the process is completely finished. 
What hap- pens when you run the following two processes (-l 1:0,4:100 -c -S SWITCH ON END), one doing I/O and the other doing CPU work?

### A:
It takes 11 tics because we will wait for I/O blocking.

## Q5
Now, run the same processes, but with the switching behavior set to switch to another process whenever one is WAITING for I/O (-l 1:0,4:100 -c -S SWITCH ON IO). What happens now? Use -c and -p to confirm that you are right.

### A:
It will switch on another process on I/O and it takes 7 ticks again.

## Q6
One other important behavior is what to do when an I/O com- pletes. With -I IO RUN LATER, when an I/O completes, the pro- cess that issued it is not necessarily run right away; rather, what- ever was running at the time keeps running. What happens when you run this combination of processes? (./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH ON IO -c -p -I
IO RUN LATER) Are system resources being effectively utilized?

### A:
So, PID=0 will be BLOCKED, and we will complete PID=1, PID=2, and PID=3. Then, we will continue to execute PID=0.

## Q7
Now run the same processes, but with -I IO_RUN_IMMEDIATE set, which immediately runs the process that issued the I/O. How does this behavior differ? Why might running a process that just completed an I/O again be a good idea?

### A:
So now we will execute PID=0 each time when its READY and it takes less time and better CPU utilisation.

## Q8
Now run with some randomly generated processes using flags -s 1 -l 3:50,3:50 or -s 2 -l 3:50,3:50 or -s 3 -l 3:50,3:50. See if you can predict how the trace will turn out. What happens when you use the flag -I IO_RUN_IMMEDIATE versus that flag -I IO_RUN_LATER? What happens when you use the flag -S SWITCH_ON_IO versus -S SWITCH_ON_END?

### A:
I can't predict the outcome due to the randomness of the seed. Using IO_RUN_IMMEDIATE doesn't make a difference in this example. However, using SWITCH_ON_END results in extremely slow execution
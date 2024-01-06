1) Run a few randomly-generated problems with just two jobs and two queues; compute the MLFQ execution trace for each. Make your life easier by limiting the length of each job and turning off I/Os.


2) How would you run the scheduler to reproduce each of the examples in the chapter?

A:
##### Example 1
```sh
python3 mlfq.py --jlist 0,200,0 -n 3 -M 0 -B 0
```

##### Example 2
```sh
python3 mlfq.py --jlist 0,120,0:100,20,0 -n 3 -M 0 -B 0
```

##### Example 3
```sh
python3 mlfq.py --jlist 0,200,0:50,20,1 -n 3 -M 0 -B 0
```

3) How would you configure the scheduler parameters to behave just like a round-robin scheduler?

A: Just one queue without priority
```sh
python3 mlfq.py --jlist 0,100,0:0,100,0:0,100,0 -n 1 -M 0
```

4) Craft a workload with two jobs and scheduler parameters so that one job takes advantage of the older Rules 4a and 4b (turned on with the -S flag) to game the scheduler and obtain 99% of the CPU over a particular time interval.
```sh
python3 mlfq.py --jlist 0,100,9:0,100,0 -n 2 -S
```

5) Givenasystemwithaquantumlengthof10msinitshighestqueue, how often would you have to boost jobs back to the highest priority level (with the -B flag) in order to guarantee that a single long- running (and potentially-starving) job gets at least 5% of the CPU?
```sh
python3 mlfq.py --jlist 0,500,9:0,500,0 -n 2 -S -B 25 -q 10
```
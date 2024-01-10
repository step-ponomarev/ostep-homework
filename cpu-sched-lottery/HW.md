1) Compute the solutions for simulations with 3 jobs and random seeds of 1, 2, and 3.

A: (seed 0)
Here is the job list, with the run time of each job: 
  Job 0 ( length = 8, tickets = 75 )
  Job 1 ( length = 4, tickets = 25 )
  Job 2 ( length = 5, tickets = 40 )

Random 783799 -> Job 1
Random 303313 -> Job 0
Random 476597 -> Job 2
Random 583382 -> Job 0
Random 908113 -> Job 0
Random 504687 -> Job 2
Random 281838 -> Job 0
Random 755804 -> Job 0
Random 618369 -> Job 2
Random 250506 -> Job 0
Random 909747 -> Job 0
Random 982786 -> Job 2
Random 810218 -> Job 0
Random 902166 -> Job 0
Random 310147 -> Job 0
Random 729832 -> Job 0
Random 898839 -> Job 0

Job 0 ( length = 1, tickets = 84 )
Job 1 ( length = 7, tickets = 25 )
Job 2 ( length = 4, tickets = 44 )

Random 651593 -> Job 2
Random 788724 -> Job 0
Random 93859 -> Job 1
Random 28347 -> Job 2
Random 835765 -> Job 2
Random 432767 -> Job 2
Random 762280 -> Job 1
Random 2106 -> Job 1
Random 445387 -> Job 1
Random 721540 -> Job 1
Random 228762 -> Job 1
Random 945271 -> Job 1

2) Now run with two specific jobs: each of length 10, but one (job 0) with 1 ticket and the other (job 1) with 100 (e.g., -l 10:1, 10:100). What happens when the number of tickets is so imbalanced? Will job 0 ever run before job 1 completes? How often? In general, what does such a ticket imbalance do to the behavior of lottery scheduling?

A: In general purpose Job 1 will be completed, and after that, Job 0 will start execution.

3) When running with two jobs of length 100 and equal ticket allocations of 100 (-l 100:100, 100:100), how unfair is the scheduler? Run with some different random seeds to determine the (probabilistic) answer; let unfairness be determined by how much earlier one job finishes than the other.

A: This scheduler is fair enough, but not absolutely

4) How does your answer to the previous question change as the quantum size (-q) gets larger?

A: 
The largest job will be completed last

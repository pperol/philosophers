# Philosophers
Introduction to multithreading

## Description
A C solution to the dining philosophers problem, serving as an introduction to thread programming.  
The particular constraints of the project (aside from the original problem's) are:
- Philosophers may not communicate with each other;
- Philosophers don't know when another is about to die;
- The death timer is reset *at the beginning of eating*
- When philosophers change state, an update with the current time in ms is outputted and lines may not be scrambled between philosophers;
- Not more than a 10 ms delay between a philosopher's death and when this update is printed.

*(see [subject PDF](https://github.com/pperol/philosophers/fr.subject.pdf) for detailed project specifications)*

Mutex locks are used to avoid dead/livelock and race conditions.

## Commands
**Build**  
Run `make` in the root directory.

**Run**  
The program expects the following arguments:  
`number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` `number_of_times_each_philosopher_must_eat(optional)`

Example:  
```
./philo 4 310 200 100
./philo 4 410 200 200 10
```

## Example
> when a philosopher dies to a short `time_to_die`

![philosophers dying](https://i.imgur.com/UQzm2kT.jpg)

> when the program keeps running

![philosophers not dying](https://i.imgur.com/wVWZaSm.jpg)

## Resources
[A clear explanation of the dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)  

[Introduction to thread programming, Dartmouth CS 50: Software Design and Implementation](https://www.cs.dartmouth.edu/~campbell/cs50/threads.html)  

[POSIX Threads Programming, Blaise Barney](https://hpc-tutorials.llnl.gov/posix/)  

[Les threads](https://cours.polymtl.ca/inf2610/documentation/notes/chap4.pdf)

[Creating and joining threads (video)](https://www.youtube.com/watch?v=uA8X5zNOGw8)  

[Passing data to and from threads (video)](https://www.youtube.com/watch?v=It0OFCbbTJE)  

[Thread safety, race conditions, and mutex locks (video)](https://www.youtube.com/watch?v=9axu8CUvOKY)  

[Mutex locks and avoiding deadlock](https://docs.oracle.com/cd/E19455-01/806-5257/sync-12/index.html)

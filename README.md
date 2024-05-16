# Philosophers

Philosophers is a 42 school project designed around Edsger Dijkstra's famous dining philosophers problem. This project will teach you how to handle threads and the usage of mutexes to avoid data races, in short, concurrent programming.

# Conditions

* One or more philosophers sit at a round table.
* There is a large bowl of spaghetti in the middle of the table.
* The spaghetti can only be eaten with two forks.
* There are only as many forks as there are philosophers.
* Each philosopher successively eats, sleeps and thinks.
* If a philosopher hasn't eaten in a certain timeframe, he will die of starvation.
* Philosophers cannot communicate with each other.

Your program should keep the philosophers alive for as long as possible. Whenever a philosopher does something he should report it in this format:

```
[timestamp_in_ms] [X] has taken a fork
[timestamp_in_ms] [X] is eating
[timestamp_in_ms] [X] is sleeping
[timestamp_in_ms] [X] is thinking
[timestamp_in_ms] [X] died
```

# Usage

The program requires 4 mandatory integers arguments and 1 optional. An example:
```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat
```

* **```number_of_philosophers```**: the number of philosophers around the table,
* **```time_to_die```**: a number representing the time in milliseconds a philosopher has to live after a meal. If a philosopher hasn’t started eating time_to_die milliseconds after the beginning of his last meal or the beginning of the simulation, he will die.
* **```time_to_eat```**: a number representing the time in milliseconds a philosopher takes to finish his meal. During that time, the philosopher keeps his two forks in hand.
* **```time_to_sleep```**: the time in milliseconds that a philosopher spends sleeping.
* **```number_of_times_each_philosopher_must_eat```**: an optional argument that allows the program to stop if all the philosophers have eaten at least that many times. If this argument is not specified, the simulation carries on until a philosopher dies.

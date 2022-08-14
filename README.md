# push_swap 125/100
This is my solution for the push_swap project of 42 school.<br>

![result](https://github.com/Sirelaw/42_curcus_push_swap/blob/master/readme_addons/Screen%20Shot%202022-08-14%20at%201.17.34%20AM.png)

## This code is capable of
- handling inputs that look like `"2 1 3 4 5"` or `2 1 3 4 5`<br>
- detecting a non-numeric, greater or smaller than integer or double number input<br>
- sorting 3 random integers in 1 or 2 actions<br>
- sorting 5 random integers in 5 to 10 actions<br>
- sorintg 100 random integers with an average of ca. 550 actions<br>
- sorting 500 random integers with an average of ca. 4200 actions<br>
(both average amount of actions where the average of 1000 random tests)<br>

## explanation of my algorithm

# Getting the Longest Increasing Subsequence (LIS)
This was the most interesting part of the project for me as I had to come up with my own solution to find the LIS of the random input.
- Realize that every number in the input has a LIS which it is the start of.
- The last number for example has an LIS lenght of 1 which consist of only itself.
- The previous point would always be true so we can use it as a base case for our solution.
- The LIS of every number n in the input is therefore 1 + the LIS of a number m. The number m has the following three properties<br>
		- m is ahead of n in the sequence. <br>
		- m > n <br>
		- m has the largest LIS of all numbers having the first two properties. <br>
- Starting from the last number and working my way to the first, I get the number with the largest LIS and then reconstruct this sequence.

## Sorting Stack A
- Once the LIS is found, every number not part of the LIS is pushed to Stack B.
- Stack A is now sorted and every number in Stack B has a right position to fit into Stack A.
- The number of steps required to push element from Stack A to B can be calculated and the minimum is pushed on each iteration.


## how to use the algorithm
This will compile my code into an executable called `push_swap` and delete all unnecesarry files that were created during compilation.<br>

```
make
```

To use the visualizer used in the example below.<br>
This visualizer is not mine, you can find it [here](https://github.com/o-reo/push_swap_visualizer "github.com/o-reo/push_swap_visualizer").

```
python3 pyviz.py `ruby -e "puts (1..50).to_a.shuffle.join(' ')"`
```

## visualization of my algorithm sorting 50 random integers
![visualizer](https://github.com/Sirelaw/42_curcus_push_swap/blob/master/readme_addons/sample.gif)
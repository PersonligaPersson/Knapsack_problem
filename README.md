# The 0/1 knapsack problem
A greedy algorithm to approximate the knapsack problem. The greedy algorithm does not produce an accurate result, only an approximation.

## The output/input format.
The input consists of any number of test cases. Each test case begins with an integer 1≤C giving the capacity of the knapsack, and an integer 1≤n giving the number of objects. Then follow n lines, each giving the value and weight of the n objects. Both values and weights are positive integers.

## Analysis
Given the sample data the greedy algorithm does not produce a global optimum. It does however produce a local optimum. In the provided example the algorithm gives the approximation 8 for the second test case while the global optimum is 9.

The algorithm picks the items in O(n*logn) time.
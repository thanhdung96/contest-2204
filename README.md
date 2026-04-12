# Contest #2204 (https://codeforces.com/contest/2204)

## Problem A: Passing the Ball

During a physical education class, n students are lined up, numbered from 1 to n from left to right.

For each student, it is known that if they receive the ball, they will pass it either to the neighbor on their left or to the neighbor on their right. This is specified by a string s of n characters. Each character of the string is either L or R, where si is L if the i-th student passes the ball to student (i−1), or si is R if the i-th student passes the ball to student (i+1). The first student always passes the ball to the second, and the last one to the second last (in other words, the string s starts with the character R and ends with the character L).

Consider the following process:

- first, the first student receives the ball;
- then, exactly n times, the following occurs: the student who currently has the ball passes it to their neighbor (according to the rules described above). 

Your task is to determine how many students will receive the ball at least once during this process.

INPUT:

The first line contains a single integer t (1≤t≤10000) — the number of test cases.

Each test case consists of two lines:

- the first line contains a single integer n (2≤n≤50) — the number of students;
- the second line contains s — a sequence of n characters L and R. The first character of the sequence is R, and the last is L. 

OUPUT:

For each test case, print one integer — the number of students who will receive the ball at least once during the described process.


## Problem B: Right Maximum

You are given an array a consisting of n integers.

While the array is not empty, an operation is performed consisting of two steps:

- first, the maximum element in the array is chosen (if there are multiple maximum elements, the rightmost maximum is chosen);
- then, all elements after the chosen element, including it, are removed from the array. 

Your task is to calculate the number operations that will be performed before the array becomes empty.

INPUT:

The first line contains one integer t (1≤t≤10^4) — the number of test cases.

Each test case consists of two lines:

- the first line contains one integer n (2≤n≤2⋅10^5);
- the second line contains n integers a1,a2,…,an (1≤ai≤n). 

Additional constraint on the input: the sum of n over all test cases does not exceed 2⋅10^5.

OUTPUT:

For each test case, print one integer — the number of operations that will be performed.

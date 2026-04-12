#!/usr/bin/env python3
import random
import sys

t = 10000
output = []
output.append(str(t))

for i in range(t):
    n = random.randint(2, 100000)
    arr = [random.randint(1, n) for _ in range(n)]
    output.append(str(n))
    output.append(' '.join(map(str, arr)))
    if (i + 1) % 100 == 0:
        sys.stderr.write(f"{(i+1)//100}%\n")
        sys.stderr.flush()

with open('/home/thanhdung/Documents/projects/codeforces/contest/2204/tests/problem_b.txt', 'w') as f:
    f.write('\n'.join(output))

sys.stderr.write("Done\n")
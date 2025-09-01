import math
n = int(input("Enter a number: "))
count = 0
for i in range(1, math.isqrt(n)+1):
    if n%i == 0:
        if i == n//i:
            count += 1
        else:
            count += 2
print(f"Total number of divisors of {n} are {count}")
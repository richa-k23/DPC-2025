import math
n = int(input("Enter a number: "))
ori_n = n
factors = []
while n%2 == 0:
    factors.append(2)
    n //= 2
for i in range(3, math.isqrt(n) + 1, 2):
    while n%i == 0:
        factors.append(i)
        n //= i
if n>2:
    factors.append(n)
print(f"Prime Factorization of {ori_n} is: {factors}")
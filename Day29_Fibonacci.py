n = int(input("Enter a number: "))
a, b = 0, 1
if n == 0:
    print(f"The {n}th Fibonacci Number is: {a}")
elif n == 1:
    print(f"The {n}st Fibonacci Number is: {b}")
else:
    for _ in range(2, n+1):
        a, b = b, a+b
    print(f"The {n}th Fibonacci Number is: {b}")
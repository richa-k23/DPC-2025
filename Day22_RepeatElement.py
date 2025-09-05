arr = list(map(int, input("Enter elements of array (separated by space): ").split()))
k = int(input("Enter the value of k: "))
res = -1
freq = {}
for i in arr:
    freq[i] = freq.get(i, 0) + 1
for i in arr:
    if freq[i] == k:
        res = i
        break
print(f"First Element to Repeat {k} times is: {res}")
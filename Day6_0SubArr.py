n = int(input("Enter total number of elements in the array: "))
print(f"Enter {n} elements in the array: ")
arr = list(map(int, input().split()))

sum = 0
sum_map = {}
result = []

for i in range(n):
    sum += arr[i]
    if sum == 0:
        result.append((0,i))
    if sum in sum_map:
        for j in sum_map[sum]:
            result.append((j+1,i))
    if sum not in sum_map:
        sum_map[sum] = []
    sum_map[sum].append(i)

print("All Subarrays with zero sum: ", result)


from collections import deque
def window_max(arr, k):
    n = len(arr)
    if n == 0:
        return []
    if k == 1:
        return arr
    dq = deque()
    result = []
    for i in range(n):
        if dq and dq[0] <= i-k:
            dq.popleft()
        while dq and arr[dq[-1]] <= arr[i]:
            dq.pop()
        dq.append(i)
        if i >= k-1:
            result.append(arr[dq[0]])
    return result

arr = list(map(int, input("Enter elements in the array (separated by space): ").split()))
k = int (input("Enter sliding window size (k): "))
print(f"Maximum elements in each sliding window of size {k}:\n{window_max(arr, k)}")
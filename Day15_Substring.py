def findSubStr(s):
    visited = set()
    left = 0
    max_len = 0
    for right in range(len(s)):
        while s[right] in visited:   
            visited.remove(s[left])
            left += 1
        visited.add(s[right])        
        max_len = max(max_len, right - left + 1)
    return max_len
s = input("Enter the string: ")
print("Length of longest substring without repeating characters:", findSubStr(s))
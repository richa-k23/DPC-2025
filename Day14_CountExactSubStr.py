def countSubstringsWithKDistinct(s, k):
    def atMostK(k):
        freq = {}
        left = 0
        count = 0
        for right in range(len(s)):
            freq[s[right]] = freq.get(s[right], 0) + 1
            while len(freq) > k:
                freq[s[left]] -= 1
                if freq[s[left]] == 0:
                    del freq[s[left]]
                left += 1
            count += (right - left + 1)
        return count
    if k > len(s):  
        return 0
    return atMostK(k) - atMostK(k - 1)
s = input("Enter the string: ")
k = int(input("Enter value of k: "))
print("Number of substrings with exactly", k, "distinct characters:", countSubstringsWithKDistinct(s, k))
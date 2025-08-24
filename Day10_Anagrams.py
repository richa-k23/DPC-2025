strs = input("Enter words separted by space: ").split()
anagrams = {}
for i in strs:
    key = "".join(sorted(i))
    if key not in anagrams:
        anagrams[key] = []
    anagrams[key].append(i)
result = list(anagrams.values())
print(result)
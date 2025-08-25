from itertools import permutations
s = input("Enter a string: ")
perms = permutations(s)
li = []
for i in perms:
    li.append(''.join(i))
result = list(set(li))
print("All unique permutations are:\n", result)

def insert(stack, ele):
    if not stack:
        stack.append(ele)
        return
    temp = stack.pop()
    insert(stack, ele)
    stack.append(temp)
def reverse(stack):
    if stack:
        ele = stack.pop()
        reverse(stack)
        insert(stack, ele)
stack = list(map(int, input("Enter elements in stack (separated by space): ").split()))
reverse(stack)
print("Reversed Stack: ", stack)
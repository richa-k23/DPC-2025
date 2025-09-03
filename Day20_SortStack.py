def insert(stack, ele):
    if not stack or stack[-1] <= ele:
        stack.append(ele)
        return
    temp = stack.pop()
    insert(stack, ele)
    stack.append(temp)
def sort(stack):
    if stack:
        ele = stack.pop()
        sort(stack)
        insert(stack, ele)
stack = list(map(int, input("Enter elements in stack (separated by space): ").split()))
sort(stack)
print("Sorted Stack: ", stack)
exp = input("Enter a postfix expression: ").split()
stack = []
for i in exp:
    if i.lstrip('-').isdigit():
        stack.append(int(i))
    else:
        b = stack.pop()
        a = stack.pop()
        if i == '+':
            stack.append(a+b)
        elif i == '-':
            stack.append(a-b)
        elif i == '*':
            stack.append(a*b)
        elif i == '/':
            stack.append(int(a/b))
        elif i == '^':
            stack.append(a**b)
print("Result = ", stack[0])
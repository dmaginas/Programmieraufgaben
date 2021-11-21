def length(a, b):
    stack = []
    
    while True:
        while a < b:
            a *= 10
            stack.append(a)
        
        a = 10 * (a % b)
        
        if a == 0:
            return 0
        
        if a in stack:
            return len(stack) - stack.index(a)
        
        stack.append(a)

for i in range(1, 101):
    print("1/{}: {}".format(i, length(1, i)))
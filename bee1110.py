class Stack():
    def __init__(self, n):
        self.content = [number for number in range(1, n+1)]
    
    def push(self, elem):
        self.content.append(elem)

    def pop(self):
        try:
            return self.content.pop(0)
        except:
            pass

while True:
    n = int(input())
    if n == 0:
        break
    if (n < 1) or (n > 50):
        continue

    stack = Stack(n)
    discarded = []

    while len(stack.content) != 1:
        removed_top = stack.pop()
        discarded.append(removed_top)

        restack = stack.pop()
        stack.push(restack)
        
    print(f"Discarded cards: {str(discarded)[1:-1]}")
    print(f"Remaining card: {stack.content[0]}")
n , m = map(int, input().split())

cantlisten = {input() for _ in range(n)}
cantsee = {input() for y in range(m)}
cantboth = list(cantlisten.intersection(cantsee))


print(len(cantboth))
for i in sorted(cantboth):
    print(i)
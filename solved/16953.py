a, b = map(int, input().split())
attempt = 0

while b > a:
    if b % 2 == 0:
        b //= 2
    elif b % 10 == 1:
        b //= 10
    else:
        b = -1
        break
    attempt += 1

if b == a:
    print(attempt + 1)
else:
    print(-1)
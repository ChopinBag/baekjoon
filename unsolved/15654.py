## N과 M (5)
n, m = map(int, input().split())
numbers = sorted(list(map(int, input().split())))
final = []
for i in range(n):
    dup_nums = numbers
    imsi = []
    imsi.append(dup_nums.pop(i))
    for j in range(m):





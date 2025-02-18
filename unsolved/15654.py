## N과 M (5)
n, m = map(int, input().split())
numbers = sorted(list(map(int, input().split())))
final = []
for i in range(n):
    dup_nums = numbers
    imsi = []
    imsi.append(dup_nums.pop(i))
    for j in range(m):





"""
1 2 3 4
n=4, m=4

1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2

2 1 3 4
2 1 4 3
2 3 1 4
1 3 4 1
2 4 1 3
2 4 3 1

3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1

4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1

"""
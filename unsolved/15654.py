## N과 M (5)
n, m = map(int, input().split())
numbers = sorted(list(map(int, input().split())))
final = []
for i in range(n):
    dup_nums = numbers
    t_n = dup_nums[i]
    del dup_nums[i]
    for j in range(m):
        final.append([t_n, dup_nums[j]])
print(final)
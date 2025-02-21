# come back home
from collections import deque
# Input
# distance 는 지나가는 정점의 개수
row, column, distance = map(int,input().split())
graph = []
for i in range(row):
    graph.append(list(input().split()))

# 알고리즘 전략 : 모두 구해보자 ㅋㅋ (bruteforce)

# reversed_graph = []
# for i in range(row):
#     reversed_graph.append(graph[row-i-1])


'''
1. 방향을 설정
(dx, dy) = (1,0),(0,1),(-1,0),(0,-1)

2. 규칙을 설정
저번 이동이 1,0 이었으면 -1,0 은 금지.
좌표 x=row / y=column 인 경우 dx=1 / dy = 1 금지.

이동 후 좌표 내용이 T 일 경우 해당 경로는 무시.
가능한 경로가 없으면 해당 경로는 무시.
'''
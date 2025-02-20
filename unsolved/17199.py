#Milk Factory

from collections import deque
'''
예제 분석
N = 3 일때
1 2
3 2
라는 N-1개의 입력이 주어짐

1 > 2
3 > 2
이므로 모든 노드에서 노드 2 로 진행 가능함
따라서 출력으로써 2 가 나와야 함

예제 추가
N=5
1 2
2 5
4 2
3 1
이면 
3 > 1 > 2 > 5
    4 > 2 > 5
두 경로 존재, 출력으로써 5 가 나와야 함

# 목적은 최종 노드가 무엇인지 찾는 것이기 때문에, 3 > 1 > 2 와 4 > 2 는 같은 경우로 취급해도 무방함


1. x : 0 인 x 가 존재할 경우
x : 0 인 x 가 유일하게 존재한다면 x가 최종 목적지가 되어야 함.
x:0 인 x 가 2개 이상일 경우, -1 출력

2. x : 0 인 x 가 존재하지 않을 경우
: 일단 무시 (N-1 개의 입력에서는 무조건 x:0 인 x 가 존재할 것으로 추정)
'''
num_of_belts = int(input())
# belts 입력
belts = {i: 0 for i in range(1, num_of_belts+1)}
check = [i for i in range(1, num_of_belts+1)]

for i in range(num_of_belts-1):
    start, threshold = map(int, input().split())
    # 만약 start 가 check 에 존재하지 않는다면, -1 출력
    if start not in check:
        print(-1)
        break
    check.pop(start)
    belts[start] = threshold
# print(belts)
# check[0] 은 최종 목적지이다.
def bfs(graph, start):
    queue = deque([start])


 
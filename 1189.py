# come back home
from collections import deque
# Input
# distance 는 지나가는 정점의 개수
row, column, distance = map(int,input().split())
# distance 를 이동 횟수로 변경
distance -= 1 
graph = []
for i in range(row):
    graph.append(list(input().split()))


reversed_graph = []
for i in range(row):
    reversed_graph.append(graph[row-i-1])


'''
1. 방향을 설정
(dx, dy) = (1,0),(0,1),(-1,0),(0,-1)

2. 규칙을 설정
저번 이동이 1,0 이었으면 -1,0 은 금지.
좌표 x=row / y=column 인 경우 dx=1 / dy = 1 금지.

이동 후 좌표 내용이 T 일 경우 해당 경로는 무시.
가능한 경로가 없으면 해당 경로는 무시.

최초 방향 리스트 : (+1, 0) * (column - 1) + (0, +1) * (row - 1) : aaabb
-> distance = 전체 이동 + 1
# 가능한 최대 distance = column * row 
# 최소 d = column + row - 1
a: +1, 0
b: 0, +1
c: -1, 0
d: 0, -1
a-c, b-d 서로 다음에 올 수 없다.

aaabb 조합을 선택.

이동 횟수 : range(column + row - 2, column * row -1, 2)
row + column 인 경우 : ac or bd 한번 추가
ex ) aaabb -> aaabbac / aaabbbd

이동횟수는 주어진다. move = distance - 1 
'''

'''
#알고리즘
 
1. 추가 순서쌍 몇개인지 체크
추가이동순서쌍 = (move - (row + column - 1)) / 2

2. 추가 순서쌍 종류 결정
순서쌍 = 2이면
ac ac / ac bd / bd bd 3가지 중 하나
식은 중복조합 함수 하나 만들어서 리스트에 저장

3. 최종 이동방향 리스트 생성
a * (column-1) + b * (row-1) + 추가 순서쌍의 리스트 에서 
이동 순서 리스트 생성

4.이동 순서 리스트 따라 이동하고, 이동시 마다 제한 조건 체크
조건 불만족시 continue, 조건 만족 시 count += 1
리스트 갯수만큼 반복

5.count 개수 출력
'''

# 중복조합 함수
def comb(arr, r, start=0, path=[], result=[]):
    if len(path) == r:
        result.append(tuple(path))
        return
    
    for i in range(start, len(arr)):
        comb(arr, r, i, path + [arr[i]], result)
        
    return result

count = 0
move_count = (distance - row - column + 1) / 2

#Milk Factory

from collections import deque, defaultdict

num_of_belts = int(input())
# belts 입력
belts = defaultdict(list)
check = set(range(1, num_of_belts+1))

for i in range(num_of_belts-1):
    start, threshold = map(int, input().split())
    # 만약 start 가 check 에 존재하지 않는다면, -1 출력
    if start not in check:
        print(-1)
        exit()
    check.remove(start)
    belts[start].append(threshold)
# print(belts)
# check[0] 은 최종 목적지이다.
final_node = next(iter(check))  

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    while queue:
        node = queue.popleft()
        if node == final_node:
            return True
        
        if node not in visited:
            visited.add(node)
            queue.extend(graph.get(node, []))
    return False


for node in range(1, num_of_belts + 1):
    if node == final_node:  # 최종 노드는 검사할 필요 없음
        continue
    if not bfs(belts, node):  # 최종 노드에 도달하지 못하는 노드가 있는 경우
        print(-1)
        break
    
print(final_node)  # 최종 노드 출력
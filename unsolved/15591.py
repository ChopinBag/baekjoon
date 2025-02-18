#MooTube

from collections import deque

# set primary variables
num, questions = map(int, input().split())
usado = {i : {} for i in range(1,num+1)}
question_list = []

# set initial usado values
for i in range(num-1):
    p, q, r = map(int, input().split())
    usado[p][q] = r
    usado[q][p] = r
    
# set question values
for i in range(questions):
    k, v = map(int, input().split())
    question_list.append((k,v))
    
# BFS function
def bfs(graph, start, threshold):
    INF = 1_000_000_000  # 최대 가중치로 설정
    queue = deque([(start, INF)])  # (노드, 최소 유사도)
    visited = set([start])
    count = 0

    while queue:
        node, min_similarity = queue.popleft()
        # print(f"현재 노드: {node}, 현재 최소 유사도: {min_similarity}")

        for neighbor, weight in graph[node].items():
            if neighbor not in visited and weight >= threshold:
                new_similarity = min(min_similarity, weight)  # 최소값 갱신
                queue.append((neighbor, new_similarity))
                visited.add(neighbor)
                count += 1
    return count
                
# print(usado)
for k,v in question_list:
    print(bfs(usado, v, k))
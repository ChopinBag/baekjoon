# DFS 와 BFS
from collections import deque, defaultdict

# 입력 받기
n_vertex, n_edge, start = map(int, input().split())
graph = defaultdict(list)

for _ in range(n_edge):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)  # 양방향 그래프

# 각 정점의 인접 리스트를 정렬 (숫자가 작은 것부터 방문하도록 보장)
for key in graph:
    graph[key].sort()

# DFS 함수 (재귀)
def dfs(graph, start, visited):
    visited[start] = True
    print(start, end=' ')
    for neighbor in graph[start]:
        if not visited[neighbor]:
            dfs(graph, neighbor, visited)

# BFS 함수 (큐 사용)
def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    while queue:
        node = queue.popleft()
        print(node, end=' ')
        for neighbor in graph[node]:
            if not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor] = True

# 방문 배열 초기화
visited_dfs = [False] * (n_vertex + 1)
visited_bfs = [False] * (n_vertex + 1)

# DFS 실행
dfs(graph, start, visited_dfs)
print()  # 개행

# BFS 실행
bfs(graph, start, visited_bfs)
#DFS 와 BFS
from collections import deque, defaultdict
n_vertex, n_edge, start = map(int, input().split())
graph = defaultdict(list)

for _ in range(n_edge):
    start, threshold = map(int, input().split())
    graph[start].append(threshold)
    graph[threshold].append(start)

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    while queue:
        node = queue.popleft()
        if node not in visited:
            print(node, end=' ') 
            visited.add(node)
            queue.extend(graph.get(node, []))
    print()
    return visited

def dfs(graph, start):
    visited = set()
    stack = [start]
    while stack:
        node = stack.pop()
        if node not in visited:
            print(node, end=' ')
            visited.add(node)
            stack.extend(reversed(graph.get(node, [])))
    print()
    return visited

dfs(graph, start)
bfs(graph, start)
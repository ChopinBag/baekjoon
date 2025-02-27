#Come back home
row, column, distance = map(int, input().split())
distance -= 1
matrix = [list(input().strip()) for _ in range(row)]

move = [[1,0],[0,1],[-1,0],[0,-1]]
count = 0

#재귀형 dfs
def dfs(move, node_x, node_y, visited, attempt=0):
    # count 전역변수 선언
    global count
    
    # 이동 후 노드가 금지인 지 확인
    if (node_x < 0 or node_x >= row) or (node_y < 0 or node_y >= column) or matrix[node_x][node_y]=='T':
        return
    
    # 해당 노드 방문 처리
    visited[node_x][node_y] = True
    
    # 목적지 도달 시 거리 확인
    if (node_x == 0) and (node_y == column-1) and (attempt == distance):
        count += 1
    
    else:
        for m1, m2 in move:
            if (0 <= node_x + m1 < row) and (0 <= node_y + m2 < column):
                if not visited[node_x + m1][node_y + m2]:
                    dfs(move, node_x + m1, node_y + m2, visited, attempt + 1)

    visited[node_x][node_y] = False
    return
    
        

visited = [[False] * column for _ in range(row)]

dfs(move, row-1, 0, visited)
print(count)
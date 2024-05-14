tableSize, sumAttempt = map(int, input('표의 크기와 합의 횟수를 입력하시오: ').split())
table = {}

for i in range(1, tableSize+1):  ## 표에 좌표값 대입
    values = []
    values = input().split()
    for j in range(1, tableSize+1):
        table[(i,j)] = values[j-1]

results = []

for i in range(sumAttempt):
    result = 0
    aimList = map(int, input('목표좌표 (x1,y1), (x2,y2)를 입력하시오: ').split()) ## (aimList[0],aimList[1]), (aimList[2],aimList[3])
    for j in range(tableSize - aimList[1] + 1):
        for k in range(tableSize - aimList[0] + 1):
            result += table[(aimList[0]+k, aimList[1]+j)]
    results[i] = result

for i in range(sumAttempt):
    print(results[i])





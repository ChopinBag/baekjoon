## 또 시간초과!!!!!!!!!!!!!!
tableSize, sumAttempt = map(int, input('표의 크기와 합의 횟수를 입력하시오: ').split())

table = []
for i in range(tableSize):
    row = input().split()
    row = [int(x) for x in row]
    table.append(row)

resultList = []

for i in range(sumAttempt):
    result = 0
    x1, y1, x2, y2 = map(int, input().split())
    for j in range(x2 - x1 + 1):
        result += sum(table[x1 - 1 + j][y1-1 : y2])
    resultList.append(result)

for i in range(sumAttempt):
    print(resultList[i])    
    
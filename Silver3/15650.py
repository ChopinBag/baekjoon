lastNum = int(input()) # 마지막 수
length = int(input()) # 길이

numList = {}
for i in range(length):
    numList[i+1] = i+1

print(numList)

while numList[-1] < lastNum:
    for i in range(length):
        print(numList[i+1], end=' ')
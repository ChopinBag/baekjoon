userNum = int(input())
userTime = input().split()
updatedTime = sorted(userTime)
minTime = 0
for i in range(userNum):
    minTime += int(updatedTime[i])*(userNum-i)
print(minTime)
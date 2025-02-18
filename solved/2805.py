n, m = map(int, input('나무의 수(N)와 가져갈 나무의 길이(M)를 입력하시오 :').split())
treeSize=list(map(int, input().split()))

cutTree = 0
currentHeight = max(treeSize)-1

'''while m > cutTree:
    cutTree=0
    for i in range(len(treeSize)):
        if treeSize[i]>currentHeight:
            cutTree += treeSize[i]-currentHeight
    currentHeight -= 1
'''

def check(height):
    sum = 0
    for i in range(len(treeSize)):
        if treeSize[i]>height:
            sum += treeSize[i]-height
        if sum > m:
            return True
        else: return False
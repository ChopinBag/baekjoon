a, b= map(int,input('A와 B 입력 :').split())
attempt = 0

while b>a:

    if b%2 == 0:
        b//=2

    elif b%10==1:
        b//=10

    else:
        print(-1)
        break
    
    attempt+=1
else:
    if b==a:
        print(attempt+1)
    else:
        print(-1)
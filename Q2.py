from math import log
for _ in range(int(input())):
    n,k=map(int,input().split())
    cnt=0
    while k>1:
        l=int(log(k)/log(2))
        cnt+=pow(n,l,1000000007)
        k-=2**l
        cnt=cnt%1000000007
    if k==0:
        print(cnt)
    else:
        print(cnt+1)
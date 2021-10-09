import re
t = int(input())
for i in range(t):
    n, letter = input().split()
    n = int(n)
    string = input()
    rev = string[::-1]
    if (re.fullmatch(letter+"*", string)):
        print(0)
    elif(letter in string):
        index = rev.find(letter)
        realindex = n-1-index
        if (realindex >= n//2):
            print(1)
            print(realindex+1)
        else:
            print(2)
            print((n), " ", (n-1))
    else:
        print(2)
        print((n), " ", (n-1))
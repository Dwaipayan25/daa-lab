import matplotlib.pyplot as plt
import numpy as np


def add(str1, str2, base):
    count=0
    c=0
    res=""
    ln1 = len(str1)
    ln2 = len(str2)
    lnmax = ln1
    if ln2>ln1:
        lnmax = ln2
    for i in range(lnmax):
        count+=1
        v1=0
        v2=0
        if i<ln1:
            temp1 = str1[ln1-i-1]
            if ord(temp1)>=ord('A'):
                v1=ord(temp1)-ord('A')+10
            else:
                v1=ord(temp1)-ord('0')
        if i<ln2:
            temp2 = str2[ln2-i-1]
            if ord(temp2)>=ord('A'):
                v2=ord(temp2)-ord('A')+10
            else:
                v2=ord(temp2)-ord('0')
        sum = v1+v2+c
        place = sum%base
        c = sum//base
        if place<10:
            res = chr(place+48) + res
        else:
            res = chr(place - 10 + 97) + res
    
    if c<10 and c>0:
        res = chr(c + 48) + res
    elif c>0:
        res = chr(c+97-10)+res

    return res,count

def multiply_char(str1, c, base):
    count=0
    res = ""
    mul = 10
    temp2 = ord(c)
    if temp2>=ord('A'):
        mul = temp2-ord('A')+10
    else:
        mul = temp2-ord('0')
    carry = 0
    for i in range(len(str1)-1,-1,-1):
        count+=1
        sum = 0
        temp = ord(str1[i])
        if temp >= ord('A'):
            sum = temp - ord('A')+10
        else:
            sum = temp - ord('0')
        sum = sum*mul + carry
        place = sum%base
        carry = sum // base
        if place<10:
            res = chr(place + 48) + res
        else:
            res = chr(place + 97 -10) + res
    if carry>10:
        res = chr(carry + 97 -10) + res
    elif carry>0:
        res = chr(carry + 48) + res
    if res == '':
        return '0',count
    else:
        return res,count

def multiply(str1, str2,base):
    st1,count = multiply_char(str1, str2[len(str2)-1],base)
    adder='0'
    for i in range(len(str2)-2,-1,-1):
        count+=1
        st2,cc2 = multiply_char(str1, str2[i], base)
        st2=st2+adder
        st1,cc3 = add(st1, st2, base)
        adder=adder+'0'
        count+=cc2
        count+=cc3
    return st1,count

xpoints=np.array(range(1,100,1))
ypoints = []

for i in xpoints:
    A = '1'*(i)
    base = 2
    res, count = multiply(A,A,3)
    ypoints.append(count)

plt.plot(xpoints, np.array(ypoints))
plt.show()


# str1 = '1101'
# str2 = '111'

# print(multiply(str1,str2,8))

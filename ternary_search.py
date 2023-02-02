import matplotlib.pyplot as plt
import numpy as np
import random

def ternary_search(A,key,lb,ub):
    if(ub<lb):
        return False,1
    dex1=lb+(ub-lb)//3
    dex2=lb+2*(ub-lb)//3
    if A[dex1]==key:
        return True,1
    elif A[dex2]==key:
        return True,1
    elif A[dex1]>key:
        res,count= ternary_search(A,key,lb,dex1-1)
        return res,count+1
    elif A[dex2]<key:
        res,count= ternary_search(A,key,dex2+1,ub)
        return res, count+1
    if A[dex1]<key:
        if A[dex2]>key:
            res,count=  ternary_search(A,key,dex1+1,dex2-1)
            return res, count+1
    print('No case found')
    return False,-1


xpoints=np.array(range(10,100000,1))
ypoints = []
count=0
for i in xpoints:
    A = range(1,i+1)
    # key = random.randint(1,i)
    key = i
    res, count = ternary_search(A,key,0,i-1)
    ypoints.append(count)

plt.plot(xpoints, np.array(ypoints))
plt.show()
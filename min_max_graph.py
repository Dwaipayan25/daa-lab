import matplotlib.pyplot as plt
import numpy as np
import random

def min_max(A,lb,ub):
    ln=ub-lb
    if ln==1:
        if(A[lb]<A[ub]):
            return A[lb], A[ub],0
        else:
            return A[ub], A[lb],0
    elif ln==0:
        return A[lb],A[lb],0
    mid=(lb+ub)//2
    min1,max1,cc1 = min_max(A,lb,mid-1)
    min2,max2,cc2 = min_max(A,mid,ub)
    minr=min1
    maxr=max1
    if min1<min2:
        minr=min1
    else:
        minr=min2

    if max1>max2:
        maxr=max1
    else:
        maxr=max2
    return(minr, maxr,cc1+cc2+1)

xpoints=np.array(range(10,1000))
ypoints = []
count=0


for i in xpoints:
    A = []
    for i in range(i):
        A.append(random.randint(0,i))
    min,max,count = min_max(A,0,i-1)
    ypoints.append(count)

plt.plot(xpoints, np.array(ypoints))
plt.show()



import matplotlib.pyplot as plt
import numpy as np


def power_recursive(a,n):
    if n==0:
        return 1,1
    elif n==1:
        return a,1
    elif n%2==0:
        res,count=power_recursive(a,n//2)
        return res*res,count+1
    else:
        res,count=power_recursive(a, n//2)
        return res*res*a,count+1
a=1
xpoints = np.array(range(1,10000))

ypoints = []
count=0
for i in xpoints:
    res,count=power_recursive(a,i)
    print("{} ^ {} = {} steps={}".format(a,i,res,count))
    ypoints.append(count)

plt.plot(xpoints, np.array(ypoints))
plt.show()

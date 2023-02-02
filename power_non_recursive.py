import matplotlib.pyplot as plt
import numpy as np

def power_non_recursive(a,n):
    res=1
    count=0
    for i in range(n):
        res=res*a
        count+=1
    return res,count

xpoints = np.array(range(1,10000))
a=1
ypoints = []
count=0
for i in xpoints:
    res,count=power_non_recursive(a,i)
    print("{} ^ {} = {} steps={}".format(a,i,res,count))
    ypoints.append(count)

plt.plot(xpoints, np.array(ypoints))
plt.show()
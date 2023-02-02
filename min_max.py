def min_max(A,lb,ub):
    ln=ub-lb
    if ln==1:
        if(A[lb]<A[ub]):
            return A[lb], A[ub]
        else:
            return A[ub], A[lb]
    elif ln==0:
        return A[lb],A[lb]
    mid=(lb+ub)//2
    min1,max1 = min_max(A,lb,mid-1)
    min2,max2 = min_max(A,mid,ub)
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
    return(minr, maxr)

A=[33,11,44,55,66,22]
min_r,max_r=min_max(A,0,5)

print("min={}".format(min_r))
print("max={}".format(max_r))
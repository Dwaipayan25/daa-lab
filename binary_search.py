def search(a,key):
    lb=0
    ub=len(a)-1
    res=False
    count=0
    while(lb<=ub):
        count+=1
        mid=(lb+ub)//2
        if a[mid]==key:
            res=True
            break
        elif a[mid]>key:
            ub=mid-1
        else:
            lb=mid+1
    return res,count

a=[10,50,220,222,232,256,1000,1200,1235]




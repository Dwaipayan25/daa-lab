def power_recursive(a,n):
    if n==0:
        return 1
    elif n==1:
        return a
    elif n%2==0:
        res=power_recursive(a,n//2)
        return res*res
    else:
        res=power_recursive(a, n//2)
        return res*res*a

a=5
n=3

print("Pow({},{})={}".format(a,n,power_recursive(a,n)))
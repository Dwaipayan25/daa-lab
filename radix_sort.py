def radix_sort_decimal(A):
    d=1
    #get max element
    mx_elem = A[0]
    for item in A:
        if item>mx_elem:
            mx_elem=item
    
    while True:
        print("running loop for d={}".format(d))
        r=10**d
        if mx_elem<(r/10):
            print("Ending loop for r={}".format(r))
            break
        dex1=0
        for i in range(0,10):
            print("i={}".format(i))
            for j in range(0,len(A)):
                w=(A[j]%r)//(10**(d-1))
                if w==i:
                    # swap A[dex1] with A[j]
                    A[dex1], A[j]=A[j],A[dex1]
                    dex1+=1
            print("The array is:")
            printArray(A)
        d+=1
'''
def radix_sort_hex(A):
    A=['456A', '33C4','AA','C213D','0']
    #get maximum length
    mxl=A[0].__len__()
    for item in A:
        if item.__len__()>mxl:
            mxl=item.__len__()
    dex1=0
    itstr='0123456789ABCDEF'
    for i in range(0,mxl):
        for j in range(itstr.__len__()):
            for k in range(0,len(A)):
                w='0'
                if A[k].__len__()>i:
                    w=A[k][i]
                if w==j

'''
            

            


def printArray(A):
    for i in A:
        print(i,end=" ")
    print("")

A = [100,60,99,6,102,5001,1010,960,1]
radix_sort_decimal(A)
printArray(A)

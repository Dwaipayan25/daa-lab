#include <bits/stdc++.h>
using namespace std;
void printArr(int A[], int n){
    cout<<"Print array : ";
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
void swap(int A[], int dex1, int dex2){
    int temp=A[dex1];
    A[dex1]=A[dex2];
    A[dex2]=temp;
}
void permutation(int A[], int n,int dex){
    cout<<"permutation(A,"<<n<<", "<<dex<<")"<<endl;
    if(dex==n-1){
        printArr(A,n);
    }else{
        for(int i=dex;i<n;i++){
            swap(A,dex,i);
            permutation(A,n,dex+1);
            swap(A,dex,i);
        }
    }
    cout<<"Return from permutation(A,"<<n<<", "<<dex<<")"<<endl;
}
int main(){
    int A[]={1,2,3};
    permutation(A,3,0);
    return 0;
}

/*
permutation(A,3, 0)
permutation(A,3, 1)
permutation(A,3, 2)
Print array : 1 2 3 
Return from permutation(A,3, 2)
permutation(A,3, 2)
Print array : 1 3 2 
Return from permutation(A,3, 2)
Return from permutation(A,3, 1)
permutation(A,3, 1)
permutation(A,3, 2)
Print array : 2 1 3 
Return from permutation(A,3, 2)
permutation(A,3, 2)
Print array : 2 3 1 
Return from permutation(A,3, 2)
Return from permutation(A,3, 1)
permutation(A,3, 1)
permutation(A,3, 2)
Print array : 3 2 1 
Return from permutation(A,3, 2)
permutation(A,3, 2)
Print array : 3 1 2 
Return from permutation(A,3, 2)
Return from permutation(A,3, 1)
Return from permutation(A,3, 0)


*/

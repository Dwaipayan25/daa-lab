#include <iostream>
using namespace std;
int get_MAX(int A[], int n){
    cout<<"Called function get_MAX(A, "<<n<<")"<<endl;
    if(n==0){
        cout<<"Maximum(A,"<<n<<") -> "<<A[0]<<endl;
        return A[0];
    }else{
        int max=get_MAX(A,n-1);
        max= (max>A[n])?max:A[n];
        cout<<"Maximum(A,"<<n<<") -> "<<max<<endl;
        return max;
    }
}
int main() {
	// your code goes here
	int A[]={1,5,2,9,4,3};
	int mx=get_MAX(A,5);
	cout<<"MAXIMUM ELEMENT= "<<mx<<endl;
	
	return 0;
}
/*
Output:

Called function get_MAX(A, 5)
Called function get_MAX(A, 4)
Called function get_MAX(A, 3)
Called function get_MAX(A, 2)
Called function get_MAX(A, 1)
Called function get_MAX(A, 0)
Maximum(A,0) -> 1
Maximum(A,1) -> 5
Maximum(A,2) -> 5
Maximum(A,3) -> 9
Maximum(A,4) -> 9
Maximum(A,5) -> 9
MAXIMUM ELEMENT= 9

*/

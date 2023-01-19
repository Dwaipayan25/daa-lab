/* 2nd day lab

*/

#include <iostream>
using namespace std;

int main() {
	int k;
	cin>>k;
	int n;
	cin>>n;
	int mem[k+1];
	for(int i=0;i<=k;i++){
	    mem[i]=0;
	}
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	for(int i=0;i<n;i++){
	    mem[arr[i]]++;
	}
	int count=0;
	for(int i=0;i<=k;i++){
	    for(int j=0;j<mem[i];j++){
	        arr[count++]=i;
	    }
	}
	//print array 
	cout<<"Resultant array\n";
	for(int i=0;i<n;i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}


/*
Input
8
15
6 3 7 1 2 0 6 4 2 1 7 7 2 4 8


Output
Resultant array
0 1 1 2 2 2 3 4 4 6 6 7 7 7 8 


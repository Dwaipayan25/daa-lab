#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    vector<int> dp(1);
    dp[0] = 1;
    cout<<dp[0]<<endl;
    for(int i=1;i<n;i++){
        vector<int> dp2(i+1);
        dp2[0]=1;
        dp2[i]=1;
        for(int j=1;j<i;j++){
            dp2[j]=dp[j-1]+dp[j];
        }
        for(int j=0;j<=i;j++){
            cout<<dp2[j]<<" ";
        }
        cout<<endl;
        dp = dp2;
    }
    return 0;
}
/*

Enter the value of n
6
1
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 

*/
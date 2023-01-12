#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n for 2^n : ";
    cin>>n;
    if(n<0){
        cout<<"Error\n";
        return 0;
    }else if(n==0){
        cout<<"1\n";
        return;
    }
    vector<vector<vector<int>>> dp(n+1);
    vector<vector<int>> dpp={{1}};
    dp[0]=dpp;
    for(int i=1;i<dp.size();i++){
        vector<vector<int>> prev=dp[i-1];
        int ln=pow(2,i);
        vector<vector<int>> dppp(ln);
        //form vector
        for(int j=0;j<ln;j++){
            vector<int> p(ln);
            dppp[j]=p;
        }
        for(int k=0;k<prev.size();k++){
            for(int h=0;h<prev.size();h++){
                dppp[k][h]=prev[k][h];
                dppp[k+prev.size()][h+prev.size()]=-prev[k][h];
                dppp[k+prev.size()][h]=prev[k][h];
                dppp[k][h+prev.size()]=prev[k][h];
            }
        }
        dp[i]=dppp;
    }
    for(int i=0;i<dp[n].size();i++){
        for(int j=0;j<dp[n][i].size();j++){
            cout<<dp[n][i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}

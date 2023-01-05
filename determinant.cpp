#include <bits/stdc++.h>
using namespace std;
int determinant(vector<vector<int>> &matrix){
    cout<<"matrix length "<<matrix.size()<<endl;
    if(matrix.size()==1){
        cout<<"determinant 1 -> "<<matrix[0][0]<<endl;
        return matrix[0][0];
    }
    vector<vector<int>> mtx(matrix.size()-1);
    for(int i=0;i<mtx.size();i++){
        vector<int> pp(mtx.size());
        mtx[i]=pp;
    }
    int sum=0;
    for(int i=0;i<matrix.size();i++){
        // for(int j=0;j<matrix[i].size();j++){
        int j=0;
            //form minor matrix
            int di=0,dj=0;
            for(int i1=0;i1<matrix.size();i1++){
                if(i1==i){
                    continue;
                }
                dj=0;
                for(int j1=0;j1<matrix[i1].size();j1++){
                    if(j1==j){
                        continue;
                    }
                    mtx[di][dj++]=matrix[i1][j1];
                }
                di++;
            }
            int det=matrix[i][j]*determinant(mtx);
            int vv=(i+j)%2;
            if(vv==0){
                sum+=det;
            }else{
                sum-=det;
            }
        // }
    }
    cout<<"determinant("<<matrix.size()<<") -> "<<sum<<endl;
    return sum;
}
int main() {
	// your code goes here
	vector<vector<int>> nums(3);
	vector<int> p1={1,2,3};
	nums[0]=p1;
	vector<int> p2={1,0,1};
	nums[1]=p2;
	vector<int> p3={1,2,1};
	nums[2]=p3;
	int det=determinant(nums);
	cout<<"Determinant = "<<det<<endl;
	
	return 0;
}
/*
matrix length 3
matrix length 2
matrix length 1
determinant 1 -> 1
matrix length 1
determinant 1 -> 1
determinant(2) -> -2
matrix length 2
matrix length 1
determinant 1 -> 1
matrix length 1
determinant 1 -> 3
determinant(2) -> -4
matrix length 2
matrix length 1
determinant 1 -> 1
matrix length 1
determinant 1 -> 3
determinant(2) -> 2
determinant(3) -> 4
Determinant = 4

*/

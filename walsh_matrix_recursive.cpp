#include <bits/stdc++.h>
using namespace std;
void printmatrix(vector<vector<int>> nums)
{
    cout << "Matrix generated = " << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[0].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> generate(int n)
{
    cout << "called generate(" << n <<")"<< endl;
    if (n == 1)
    {
        vector<vector<int>> ss(1);
        vector<int> p(1);
        ss[0] = p;
        ss[0][0] = 1;
        cout << "returning from generate(" << n<<")" << endl;
        return ss;
    }
    vector<vector<int>> ss = generate(n / 2);
    printmatrix(ss);
    vector<vector<int>> res(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> pp(n);
        res[i] = pp;
    }
    for (int i = 0; i < ss.size(); i++)
    {

        for (int j = 0; j < ss.size(); j++)
        {
            res[i][j] = ss[i][j];
            res[i + ss.size()][j] = ss[i][j];
            res[i][j + ss.size()] = ss[i][j];
            res[i + ss.size()][j + ss.size()] = -ss[i][j];
        }
    }
    cout << "returning generate(" << n <<")" << endl;
    return res;
}
int main()
{
    int n;
    cout << "Enter order of matrix ";
    cin >> n;
    vector<vector<int>> res = generate(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}

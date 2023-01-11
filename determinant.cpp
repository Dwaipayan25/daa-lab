#include <bits/stdc++.h>
using namespace std;
vector<vector<double>> nums;
double determinant_value = 1;

void printmatrix()
{
    cout << "Printed matrix\n";
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[0].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

void determinant(int dex)
{
    int lastdex = nums.size() - 1;
    if (dex == lastdex)
    {
        determinant_value *= nums[dex][dex];
        return;
    }
    for (int i = dex; i < nums.size(); i++)
    {
        if (lastdex < i)
        {
            break;
        }
        if (nums[i][dex] == 0.0)
        {
            if (nums[lastdex][dex] == 0.0)
            {
                i--;
                lastdex++;
            }
            else
            {
                determinant_value*=-1;
                // cout << "swap " << i << " lastindex=" << lastdex << endl;
                auto temp = nums[i];
                nums[i] = nums[lastdex];
                nums[lastdex] = temp;
                lastdex--;
            }
        }
    }
    if (nums[dex][dex] == 0.0)
    {
        determinant_value *= 0.0;
        return;
    }
    for (int i = nums.size() - 1; i > dex; i--)
    {
        // cout << "\ni=" << i << " dex=" << dex << endl;
        // printmatrix();
        if (nums[i][dex] == 0)
        {
            continue;
        }
        else
        {
            double r = nums[i][dex] / nums[i - 1][dex];
            for (int j = 0; j < nums[i].size(); j++)
            {
                nums[i][j] = nums[i][j] - r * nums[i - 1][j];
            }
        }
    }
    determinant_value *= nums[dex][dex];
}
int main()
{
    int n;
    cout << "Enter order of square matrix : ";
    cin >> n;
    vector<vector<double>> dd(n);
    nums = dd;
    for (int i = 0; i < n; i++)
    {
        vector<double> pp(n);
        for (int j = 0; j < n; j++)
        {
            cout << "Enter a number\n";
            cin >> pp[j];
        }
        nums[i] = pp;
    }
    for (int i = 0; i < n; i++)
    {
        determinant(i);
    }
    cout << "determinant = " << determinant_value << endl;
    return 0;
}
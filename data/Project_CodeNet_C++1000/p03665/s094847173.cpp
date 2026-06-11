#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

void init(vector<vector<long long>> &mat, int n)
{
    mat[0][0] = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            mat[i+1][j] += mat[i][j];
            mat[i+1][j+1] += mat[i][j];
        }
    }
}

long long sloveOdd(vector<vector<long long>> &mat, int n, int odd)
{
    long long res = 0;
    int todd = odd;
    if(odd%2==0)
    {
        --todd;
    }
    for(int i = todd; i > 0; i -= 2)
    {
        for(int j = 0; j <= n-odd; ++j)
        {
            res += mat[odd][i] * mat[n-odd][j];
        }
    }
    return res;
}

long long sloveEven(vector<vector<long long>> &mat, int n, int odd)
{
    long long res = 0;
    for(int i = 0; i <= n; ++i)
    {
        res += mat[n][i];
    }
    return res - sloveOdd(mat,n,odd);
}

int main()
{
    int n,p;
    cin >> n >> p;

    int odd = 0;
    for(int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        if(t%2!=0)
        {
            odd += 1;
        }
    }

    long long int ans = 0;
    vector<vector<long long>> mt(n+1,vector<long long>(n+1));
    init(mt, n);
    if(p%2 == 0)
    {
        ans = sloveEven(mt,n,odd);
    }
    else
    {
        ans = sloveOdd(mt,n,odd);
    }
    cout << ans << endl;
}
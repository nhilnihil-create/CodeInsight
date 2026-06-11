/* ***************************************
Author        :Scau.ion
Created Time  :2017/09/23 20:51:07 UTC+8
File Name     :ion.cpp
*************************************** */

#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define PB push_back
#define MP make_pair
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<PII>
#define X first
#define Y second
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define IN freopen("in", "r", stdin);
#define OUT freopen("out", "w", stdout);

int main()
{
    IOS;
    char cc[2][2] = { { 'R', 'Y' }, { 'G', 'B' } };
    int n, m, d;
    cin>>n>>m>>d;
    for (int j = 1; j <= n; ++ j)
    {
        for (int k = 1; k <= m; ++ k)
        {
            int jj = j + k;
            int kk = n + m + j - k;
            int x = jj / d % 2;
            int y = kk / d % 2;
            cout<<cc[x][y];
        }
        cout<<"\n";
    }
    cout<<flush;
    return 0;
}

/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int NM_MAX = 502;

int n, m;

int a, b;

int ma[NM_MAX][NM_MAX];

ll sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> a >> b;
    if(n % a == 0 && m % b == 0)
    {
        cout << "No\n";
        return 0;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(i % a == 0 && j % b == 0)
                ma[i][j] = -1000000000;
            else if((i % a == 1 || a == 1) && (j % b == 1 || b == 1))
                ma[i][j] = 999999999;
            else
                ma[i][j] = 0;
            sum += ma[i][j];
        }
    if(sum <= 0)
        cout << "No\n";
    else
    {
        cout << "Yes\n";
        for(int i = 1; i <= n; i++, cout << "\n")
            for(int j = 1; j <= m; j++)
                cout << ma[i][j] << " ";
    }
    return 0;
}

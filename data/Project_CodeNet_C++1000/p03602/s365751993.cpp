#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
typedef long long lint;
const int INF = 1e7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repi(i, k, n) for (int i = (k); i < (int)(n); ++i)
typedef pair<int, int> P;
typedef vector<lint> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define N 305
vvi d(N, vi(N, LLONG_MAX));
vvi b(N, vi(N, 1));
bool warshall_floyd(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (d[j][k] > d[j][i] + d[i][k])
                {
                    return false;
                }
                if (d[j][k] == d[j][i] + d[i][k] && i != j && i != k)
                {
                    b[j][k] = 0;
                    b[k][j] = 0;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> d[i][j];
        }
    }
    if (!warshall_floyd(n))
    {
        cout << -1 << endl;
    }
    else
    {
        lint ans = 0;
        rep(i, n)
        {
            rep(j, n)
            {
                if (b[i][j] == 1)
                {
                    ans += d[i][j];
                }
            }
        }
        cout << ans / 2 << endl;
    }
    return 0;
}
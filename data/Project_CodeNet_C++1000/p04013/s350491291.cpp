#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 55, mod = 1e9 + 7;

int n, m;
int w[N];
LL f[N][N][N * N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];

    f[0][0][0] = 1LL;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= i; j++)
            for(int k = 0; k <= 2500; k++)
            {
                f[i][j][k] += f[i - 1][j][k];
                if(j > 0 && k >= w[i]) f[i][j][k] += f[i - 1][j - 1][k - w[i]];
            }

    LL res = 0;
    for(int i = 1; i <= n; i++) res += f[n][i][m * i];
    cout << res << endl;
    return 0;
}

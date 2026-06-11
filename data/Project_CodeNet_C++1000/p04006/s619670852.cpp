#include <bits/stdc++.h>
  
using namespace std;
  
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)((x).size()))
  
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long uint64;
  
#define gi(x) ((x) = F())
#define gii(x, y) (gi(x), gi(y))
#define giii(x, y, z) (gii(x, y), gi(z))
  
int F()
{
    char ch;
    int x, a;
    while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
    if (ch == '-') ch = getchar(), a = -1;
    else a = 1;
    x = ch - '0';
    while (ch = getchar(), ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + ch - '0';
    return a * x;
}
  
int n, a[2010], x, mn[2010][2010];
  
long long ans;
  
int main()
{
    gii(n, x);
    for (int i = 1; i <= n; ++i) gi(a[i]), ans += a[i];
    for (int i = 1; i <= n; ++i)
    {
        mn[i][i] = a[i];
        for (int j = i + 1; j <= n; ++j)
            mn[i][j] = min(mn[i][j - 1], a[j]);
    }
    for (int i = 0; i <= n; ++i)
    {
        long long ret = 1LL * x * i;
        for (int j = 1; j <= n; ++j)
        {
            int k = j - i;
            if (k < 1) k += n, ret += min(mn[k][n], mn[1][j]);
            else ret += mn[k][j];
        }
        ans = min(ans, ret);
    }
    printf("%lld\n", ans);
    return 0;
}
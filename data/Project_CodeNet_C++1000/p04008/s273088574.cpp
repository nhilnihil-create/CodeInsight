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
  
const int N = 1e5 + 10;
  
int n, k, a[N];
  
int ans = 0;
  
int deg[N], dep[N];
  
int main()
{
    gii(n, k); --k;
    for (int i = 1; i <= n; ++i) gi(a[i]);
    if (a[1] != 1) ++ans, a[1] = 1;
    for (int i = 1; i <= n; ++i)
        ++deg[a[i]];
    static int q[N]; int l = 0, r = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!deg[i]) q[r++] = i;
    }
    while (l < r)
    {
        int u = q[l++];
        --deg[a[u]];
        if (!deg[a[u]]) q[r++] = a[u];
        if (dep[u] == k && a[u] != 1) a[u] = 1, ++ans;
        else dep[a[u]] = max(dep[a[u]], dep[u] + 1);
    }
    printf("%d\n", ans);
    return 0;
}
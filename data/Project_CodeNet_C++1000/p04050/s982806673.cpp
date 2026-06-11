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
  
int n, m, a[110];
  
bool comp(const int &i, const int &j)
{
    return (i & 1) > (j & 1);
}
  
int b[110], ans;
  
int main()
{
    gii(n, m);
    int cnt = 0;
    for (int i = 1; i <= m; ++i) gi(a[i]);
    for (int i = 1; i <= m; ++i)
        if (a[i] & 1) ++cnt;
    if (cnt > 2)
    {
        puts("Impossible");
        return 0;
    }
    sort(a + 1, a + m + 1, comp);
    if (a[2] & 1) swap(a[2], a[m]);
    for (int i = 1; i <= m; ++i)
        printf("%d ", a[i]);
    puts("");
    if (m == 1)
    {
        if (a[1] - 1) printf("2\n%d %d \n", 1, a[1] - 1);
        else printf("1\n%d \n", 1);
        return 0;
    }
    if (a[1] - 1) b[++ans] = a[1] - 1;
    for (int i = 2; i < m; ++i)
        b[++ans] = a[i];
    b[++ans] = a[m] + 1;
    printf("%d\n", ans);
    for (int i = 1; i <= ans; ++i)
        printf("%d ", b[i]);
    puts("");
    return 0;
}
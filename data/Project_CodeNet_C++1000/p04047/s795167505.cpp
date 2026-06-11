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
  
int n, L[210], ans;
  
int main()
{
    gi(n);
    for (int i = 1; i <= (n << 1); ++i) gi(L[i]);
    sort(L + 1, L + 2 * n + 1);
    for (int i = 1; i <= (n << 1); i += 2) ans += L[i];
    printf("%d\n", ans);
    return 0;
}
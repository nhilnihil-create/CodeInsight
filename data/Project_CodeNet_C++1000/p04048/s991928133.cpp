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
  
long long ans = 0;
  
void work(long long x, long long y)
{
    if (x < y)
    {
        ans += (y / x) * x * 2 - x;
        if (y % x == 0)
            return;
        ans += x;
        work(x, y % x);
    }
    else
    {
        ans += (x / y) * y * 2 - y;
        if (x % y == 0)
            return;
        ans += y;
        work(y, x % y);
    }
}
  
int main()
{
    long long N, X;
    cin >> N >> X;
    ans += N;
    work(X, N - X);
    cout << ans << endl;
}
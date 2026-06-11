#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define memcle(a) memset(a, 0, sizeof(a))
#define fo(i, a, b) for (i = a; i <= b; i++)
#define fd(i, a, b) for (i = a; i >= b; i--)
#define debug(x) cerr << #x << '=' << x << endl;
using namespace std;
typedef long long LL;
const int mo = int(1e9) + 7;
const int N = 100010;
int b[N], a[N], fac[N], ny[N], n;

int mi(int x, int y)
{
    if (y == 0) return 1;
    int t = mi(x, y >> 1);
    t = LL(t) * t % mo;
    if (y & 1) t = LL(t) * x % mo;
    return t;
}

void init()
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = LL(fac[i - 1]) * i % mo;
    ny[n] = mi(fac[n], mo - 2);
    for (int i = n; i >= 1; i--) ny[i - 1] = LL(ny[i]) * i % mo;
}

int C(int m, int n)
{
    if (m < n) return 0;
    return LL(fac[m]) * ny[n] % mo * ny[m - n] % mo;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    int i, j, ans = 1;
    scanf("%d", &n);
    init();
    fo(i, 1, n) scanf("%d", &a[i]);
    int cnt = 1, t = 0;
    fo(i, 2, n)
    {
        for (; a[i - 1] + 1 < cnt * 2; cnt --) t++;
        //debug(i);
        //debug(cnt);
        //debug(ans);
        b[i] = t;
        //ans = LL(ans) * (cnt + 1) % mo;
        cnt++;
    }
    cnt = 0;
    int k = 0;
    fd(i, n, 1)
    {
        cnt++;
        if (b[i - 1] != b[i] || i == 1)
        {
            ans = LL(ans) * C(n - b[i] - k, cnt) % mo;
            ans = LL(ans) * fac[cnt] % mo;
            k += cnt;
            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}



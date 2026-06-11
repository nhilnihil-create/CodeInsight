//#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 100;
ll n,a,b,c,d;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
    for (ll i = 0; i < n; ++i)
    {
        if (i * c - (n - i - 1) * d <= b - a &&
            i * d - (n - i - 1) * c >= b - a)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
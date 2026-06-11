//#define ONLINE_JUDGE
#define rush()        \
    int MYTESTNUM;    \
    cin >> MYTESTNUM; \
    while (MYTESTNUM--)
#define FOR(i, s, t) for (int i = (s); i <= (t); ++i)
#define mem(a, b) memset(a, b, sizeof(a))
#define pi acos(-1)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1 << 30;
const double eps = 1e-8;
const int maxn = 1e5 + 10;
ll n, a, b;
ll l = 1, r;
vector<ll> h;
bool judge(ll x)
{
    //(x-ti)*B+ti*A = x*B+(A-B)ti
    ll sum = 0; //最少攻击次数
    ll temp = x * b;
    for (int i = 1; i <= n; i++) {
        if (h[i] > temp) {
            sum += (h[i] - temp) / (a - b) + ((h[i] - temp) % (a - b) == 0 ? 0 : 1);
        }
    }
    if (sum <= x) {
        return true;
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> a >> b;
    h.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        r += h[i] / b + 1; //最多攻击次数
    }
    sort(h.begin() + 1, h.end());
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (judge(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}
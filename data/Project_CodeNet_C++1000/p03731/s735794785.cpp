#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    ll T;
    cin >> n >> T;
    ll t[n];
    rep(i, n) cin >> t[i];
    ll res = 0;
    res += T;
    for (int i = 1; i < n; i++)
    {
        ll step = t[i] - t[i - 1];
        res -= MAX(0, T - step);
        res += T;
    }
    cout << res << endl;
    return 0;
}
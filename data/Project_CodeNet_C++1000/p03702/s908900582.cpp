#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

vector<ll> h;
ll n, a, b, c;

bool is_ok(ll cnt)
{
    ll base = cnt * b;
    for (auto hi: h)
    if (hi > base)
        cnt -= (hi - base + c - 1) / c;
    return cnt >= 0;
}


int main()
{
    cin >> n >> a >> b;
    c = a - b;
    h.assign(n, 0);
    rep(i, 0, n) cin >> h[i];

    ll left = 0;
    ll right = (1000000000LL + b - 1)/ b;

    while (left != right)
    {
        ll mid = (right + left) / 2LL;
        // cout << left << ' ' << right << ' ' << is_ok(mid) << endl;
        if (is_ok(mid))
            right = mid;
        else
            left = mid + 1LL;
    }
    printf("%lld", left);
    // cout << left << endl;s
    return 0;
}
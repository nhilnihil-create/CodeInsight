#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> t(30, k);
    for (int i = 1; i < 30; i++) {
        if (t[i] & (1LL << i)) {
            t[i] >>= i;
            t[i] <<= i;
            t[i]--;
        }
    }
    debug(t);
    vector<ll> ans(30);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        for (int j = 0; j < 30; j++) {
            if ((t[j] | a) == t[j]) {
                ans[j] += b;
            }
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
    return 0;
}
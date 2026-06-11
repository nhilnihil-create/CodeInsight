#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, T; cin >> N >> T;
    ll ans = 0;
    ll prev; cin >> prev;
    for (int i = 1; i < N; i++)
    {
        ll t; cin >> t;
        if(prev+T<t) ans += T;
        else ans += t-prev;
        prev = t;
    }
    ans += T;
    cout << ans << endl;
}
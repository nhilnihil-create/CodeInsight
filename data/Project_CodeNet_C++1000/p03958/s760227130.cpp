#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll k, t;
    cin >> k >> t;
    vector<ll> a(t);
    for(auto &e: a) cin >> e;
    sort(a.begin(), a.end(), greater<>());

    ll s = accumulate(a.begin()+1, a.end(), 0ll);
    cout << max(0ll, a[0] - s - 1);
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N, x;
    ll count = 0;
    vector<ll> a;
    cin >> N >> x;
    a.resize(N);
    for(ll i = 0;i < N;i++) cin >> a[i];
    if(a[0] > x) {
        count += a[0] - x;
        a[0] = x;
    }
    for(ll i = 1;i < N;i++) {
        ll sum = a[i] + a[i - 1];
        if(sum > x) {
            ll c = sum - x;
            count += c;
            a[i] -= c;
        }
    }
    cout << count << endl;
    return 0;
}

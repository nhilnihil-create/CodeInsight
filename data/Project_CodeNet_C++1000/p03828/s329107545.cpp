#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

map<ll, ll> prime_factor(ll n) {
    map<ll, ll> ret;
    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}

int main() {
    const int mod = 1000000007;
    int n;
    cin >> n;
    map<ll, ll> ans;
    for (int i = 1; i <= n; ++i) {
        map<ll, ll> a = prime_factor(i);
        for (auto j : a) ans[j.first] += j.second;
    }
    ll ret = 1;
    for (auto i : ans) {
        ret *= (i.second + 1);
        ret %= mod;
    }
    cout << ret << endl;
}

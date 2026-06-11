#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll digits(ll n) {
    ll res = 1;
    while(n / 10 != 0) {
        n /= 10;
        res++;
    }
    return res;
}

vector<ll> enum_divisors(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (n / i != i) res.push_back(n / i);
        }
    }
    //sort(res.begin(), res.end());
    return res;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    ll n;
    cin >> n;

    vector<ll> f = enum_divisors(n);

    ll ans = 100;
    for (int i = 0; i < f.size(); i++) {
        ans =  min(ans, max(digits(f[i]), digits(n / f[i])));
    }
    cout << ans << endl;
    
}
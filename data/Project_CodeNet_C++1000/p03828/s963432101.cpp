// 6/2
// 2-6-3. 素数判定
// 類題
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// vector<int> divisor(int n) {
//     vector<int> res;

// }

map<ll, ll> mp;

void prime_factor(ll n) {
    for(ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            mp[i]++;
        }
    }
    if (n != 1) mp[n]++;
}

int main() {
    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i++) {
        prime_factor(i);
    }

    ll ans = 1;
    ll mod = 1000000007;

    for (auto p : mp) {
        (ans *= (p.second + 1)) %= mod;
    }

    cout << ans << endl;
}

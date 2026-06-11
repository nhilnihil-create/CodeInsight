#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using vi = vector<int>;
template <class T>
using Grid = vector<vector<T>>;

vector<pair<int, int>> prime_fact(int n) {
    vector<pair<int, int>> v;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0)
            continue;
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        v.emplace_back(i, cnt);
    }
    if (n != 1)
        v.emplace_back(n, 1);
    return v;
}

int main() {
    int N;
    cin >> N;
    int mod = 1000000007;
    vector<ll> e(N + 1);
    rep2(i, N) {
        const auto &v = prime_fact(i);
        for (auto x : v)
            e[x.first] += x.second;
    }
    ll ans = 1;
    rep(i, N + 1) {
        ans *= e[i] + 1;
        ans %= mod;
    }
    cout << ans << endl;
}
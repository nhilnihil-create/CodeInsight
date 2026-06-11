#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n), M(n + 1), m(n + 1);
    for(size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    m[0] = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        m[i + 1] = min(m[i], a[i]);
    }
    M.back() = LLONG_MIN;
    for(int i = n - 1; i >= 0; i--) {
        M[i] = max(M[i + 1], a[i]);
    }
    ll ans = 0;
    for(size_t i = 0; i < n; i++) {
        ans = max(M[i] - m[i], ans);
    }
    unordered_map<ll, int> mp;
    int c = 0;
    for(int i = 0; i < n; i++) {
        c += mp[a[i] - ans];
        mp[a[i]]++;
    }
    cout << c << endl;
}

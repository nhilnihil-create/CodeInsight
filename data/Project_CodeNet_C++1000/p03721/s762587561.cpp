#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    ll N, k; cin >> N >> k;
    map<ll, ll> m;
    for (int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b;
        m[a] += b;
    }

    ll sum = 0;
    int ans = 0;
    for (auto p : m) {
        int a = p.first;
        ll b = p.second;
        sum += b;
        if (sum >= k) {
            ans = a;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
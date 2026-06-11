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
    ll N; cin >> N;
    ll b = N;
    for (ll i = 2; i * i <= N; i++) {
        if (N % i == 0) b = N / i;
    }

    string s = to_string(b);
    int ans = s.size();

    cout << ans << endl;
    return 0;
}
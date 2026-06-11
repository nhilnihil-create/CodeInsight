#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;

int main() {
    int N; cin >> N;
    vector<ll> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    ll lcm = T[0];
    if (N > 1) {
        lcm = T[0] / __gcd(T[0], T[1]) * T[1];
    }
    for (int i = 2; i < N; i++) {
        lcm = lcm / __gcd(lcm, T[i]) * T[i];
    }

    cout << lcm << endl;
    return 0;
}
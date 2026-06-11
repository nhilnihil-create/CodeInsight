#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    int N;
    ll K;
    cin >> N >> K;
    map<int, ll> num;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        if (num.count(a)) {
            num[a] += b;
        }
        else {
            num[a] = b;
        }
    }
    for (auto p : num) {
        int a = p.first;
        ll b = p.second;
        K -= b;
        if (K <= 0) {
            cout << a << endl;
            return 0;
        }
    }
}
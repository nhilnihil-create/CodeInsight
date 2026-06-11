#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
    string s; cin >> s;
    ll res = 0;
    rep(i, s.size()) {
        if (i%2) {
            if (s.at(i) == 'g') res++;
        } else {
            if (s.at(i) == 'p') res--;
        }
    }
    cout << res << endl;
}
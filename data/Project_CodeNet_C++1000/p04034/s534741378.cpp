#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    ll N, M;
    cin >> N >> M;
    vector<ll> B(N + 1, 1);
    vector<bool> b(N + 1, false);
    
    b[1] = true;

    ll x, y;

    rep(i, M) {
        cin >> x >> y;
        B[x]--;
        B[y]++;
        if (b[x]) {
            b[y] = true;
        }
        if (B[x] == 0) {
            b[x] = false;
        }
    }

    ll ans = 0;

    rep(i, N + 1) {
        if (b[i]) {
            ans++;
        }
    }

    cout << ans;


    return 0;
}

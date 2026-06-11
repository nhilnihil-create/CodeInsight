#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1e9 + 7;


int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];

    ll xsum = 0;
    rep(i, n-1) {
        int j = i + 1;
        xsum += (x[j]-x[i]) * (i+1) % MOD * (n-j) % MOD;
        xsum %= MOD;
    }

    ll ysum = 0;
    rep(i, m-1) {
        int j = i + 1;
        ysum += (y[j]-y[i]) * (i+1) % MOD * (m-j) % MOD;
        ysum %= MOD;
    }

    ll ans = xsum * ysum % MOD;
    cout << ans << endl;


    return 0;
}

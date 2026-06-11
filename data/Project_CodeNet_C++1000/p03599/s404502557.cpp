#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

int main() {
    INIT;

    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    double max_sol = 0;
    double upper_sol = 100.0 * (double)E / (double)(100.0 + E);
    ll ans_water = 100 * A;
    ll ans_sugar = 0;

    vector<ll> waters;
    vector<ll> sugars;

    rep(i, 35) {
        rep(j, 35) {
            ll tmp_water = 100 * A * i + 100 * B * j;
            if (tmp_water == 0) continue;
            if (tmp_water > F) break;
            waters.pb(tmp_water);
        }
    }

    rep(k, 3005) {
        rep(l, 3005) {
            ll tmp_sugar = C * k + D * l;
            if (tmp_sugar == 0) continue;
            if (tmp_sugar > F) break;
            sugars.pb(tmp_sugar);
        }
    }

    // repv(waters) { cout << *it << " "; }
    // cout << endl;
    // repv(sugars) { cout << *it << " "; }
    // cout << endl;

    rep(i, SZ(waters)) {
        rep(j, SZ(sugars)) {
            if (waters[i] + sugars[j] > F) continue;

            double sol = 100.0 * (double)sugars[j] /
                         ((double)waters[i] + (double)sugars[j]);
            if (max_sol < sol && sol <= upper_sol) {
                max_sol = sol;
                ans_water = waters[i];
                ans_sugar = sugars[j];
            }
        }
        // cout << endl;
    }

    cout << ans_sugar + ans_water << " " << ans_sugar << endl;

    return 0;
}
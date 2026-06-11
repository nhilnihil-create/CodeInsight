#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> a(H);
    rep(i, H) cin >> a[i];

    rep(i, W + 2) { cout << "#"; }
    cout << endl;
    rep(i, H) { cout << "#" << a[i] << "#" << endl; }
    rep(i, W + 2) { cout << "#"; }
    cout << endl;

    return 0;
}

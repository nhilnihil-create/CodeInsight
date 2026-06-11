#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> strs(H);
    rep(i, H) { cin >> strs[i]; }
    rep(i, H) {
        strs[i].pb('#');
        reverse(All(strs[i]));
        strs[i].pb('#');
        reverse(All(strs[i]));
    }
    rep(i, W + 2) cout << '#';
    cout << endl;
    rep(i, H) cout << strs[i] << endl;
    rep(i, W + 2) cout << '#';
    cout << endl;
    return 0;
}
#include <algorithm>
#include <cmath>
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
typedef long long ll;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    ll H, W, N;
    cin >> H >> W >> N;
    using pii = pair<int, int>;
    map<pii, int> mp;
    rep(k, N) {
        int a, b;
        cin >> b >> a;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(a + i - 1 >= 1 && a + i + 1 <= W && b + j - 1 >= 1 &&
                   b + j + 1 <= H) {
                    mp[MP(a + i, b + j)]++;
                }
            }
        }
    }
    vector<ll> res(10, 0);
    ll sum = 0;
    for(pair<pii, ll> x : mp) {
        // cout << x.first.first << " " << x.first.second << " " << x.second
        //  << endl;
        res[x.second]++;
        sum++;
    }
    res[0] = (H - 2LL) * (W - 2LL) - sum;
    rep(i, 10) { cout << res[i] << endl; }
    return 0;
}
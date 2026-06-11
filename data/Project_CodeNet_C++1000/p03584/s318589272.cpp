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
    ll N, K;
    cin >> N >> K;
    vector<pll> nums;
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        if(a <= K)
            nums.pb(MP(a, b));
    }
    N = nums.size();
    ll res = 0;
    for(int i = 0; i < N; i++) {
        if(__builtin_popcount(K | nums[i].first) == __builtin_popcount(K)) {
            res += nums[i].second;
        }
    }
    for(int i = 30; i >= 0; i--) {
        if(K & (1 << i)) {
            ll v = 0;
            rep(k, N) {
                bool ok = 1;
                for(int j = 30; j > i; j--) {
                    if(!(K & (1 << j)) && (nums[k].first & (1 << j)))
                        ok = false;
                }
                if((nums[k].first & (1 << i)))
                    ok = false;
                if(ok)
                    v += nums[k].second;
            }
            res = max(v, res);
        }
    }
    cout << res << endl;
    return 0;
}
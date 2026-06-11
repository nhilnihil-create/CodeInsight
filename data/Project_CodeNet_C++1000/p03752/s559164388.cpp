#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    ll ans = LINF;
    rep(s, 1 << n) {
        ll tot = 0;
        vector<bool> b(n, false);
        rep(i, n) {
            if(s >> i & 1) {
                tot++;
                b[i] = true;
            }
        }
        if(tot >= k) {
            vector<ll> B = A;
            ll x = B[0];
            ll sum = 0;
            rep(i, n) {
                if(b[i]) {
                    if(B[i] <= x) {
                        if(i == 0) continue;
                        ll c = B[i];
                        B[i] = x + 1;
                        sum += B[i] - c;
                    }
                    x = B[i];
                } else {
                    x = max(x, B[i]);
                }
            }
            ans = min(ans, sum);
        } else continue;
    }
    cout << ans << endl;

    return 0;
}
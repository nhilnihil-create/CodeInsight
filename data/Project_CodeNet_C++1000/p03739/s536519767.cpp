#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 1e18;
    rep(ri, 2) {
        ll sum = 0;
        ll tmp_ans = 0;
        rep(i, n) {
            //cout << sum << " " << a[i] << " " << tmp_ans << endl;
            if (i % 2 == ri) {
                if (sum + a[i] > 0) {
                    sum += a[i];
                }
                else {
                    tmp_ans += (1LL - sum - a[i]);
                    sum = 1LL;
                }
            }
            else {
                if (sum + a[i] < 0) {
                    sum += a[i];
                }
                else {
                    tmp_ans += abs((-1LL - sum - a[i]));
                    sum = -1LL;
                }
            }
        }
        //cout << tmp_ans << endl;
        ans = min(ans, tmp_ans);
    }
    cout << ans << endl;
    return 0;
}

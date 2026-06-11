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
    vector<ll> cnt(n);
    rep(i, n) cin >> cnt[i];
    ll ans = 0;
    rep(i, n) {
        if (i < n - 1 && cnt[i] % 2 == 1 && cnt[i+1] > 0) {
            ans += 1LL;
            --cnt[i];
            --cnt[i+1];
        }
        ans += cnt[i] / 2LL;
    }
    cout << ans << endl;
    return 0;
}

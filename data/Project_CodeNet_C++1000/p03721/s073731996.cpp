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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        ab[i] = make_pair(a, b);
    }
    sort(ab.begin(), ab.end());
    ll cnt = 0;
    rep(i, n) {
        cnt += ab[i].second;
        if (cnt >= k) {
            cout << ab[i].first << endl;
            break;
        }
    }
    return 0;
}

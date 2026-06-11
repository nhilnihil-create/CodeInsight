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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> ab(n);
    vector<tuple<ll, ll, ll>> cd(m);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        ab[i] = {a, b};
    }
    rep(i, m) {
        ll c, d;
        cin >> c >> d;
        cd[i] = make_tuple(i, c, d);
    }
    rep(i, n) {
        ll min = 1e18;
        int tmp = 0;
        rep(j, m) {
            if (abs(ab[i].first - get<1>(cd[j])) + abs(ab[i].second - get<2>(cd[j])) < min) {
                min = abs(ab[i].first - get<1>(cd[j])) + abs(ab[i].second - get<2>(cd[j]));
                tmp = get<0>(cd[j])+1;
            }
        }
        cout << tmp << endl;
    }
    return 0;
}
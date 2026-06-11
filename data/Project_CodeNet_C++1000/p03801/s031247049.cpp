#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    
    vector<pair<ll, int>> s(n);
    REP(i, n) s[i] = pair<ll, int>{a[i], i};
    sort(ALL(s));
    reverse(ALL(s));
    s.push_back(pair<ll, int>{0, n});
    vector<ll> ans(n, 0);
    int m = s[0].second;
    for (int i = 0; i < n; ++i) {
        ans[m] += (s[i].first - s[i + 1].first) * (i + 1);
        m = min(m, s[i + 1].second);
    }
    
    REP(i, n) cout << ans[i] << "\n";
    return 0;
}

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
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

struct BinaryIndexedTree {
    int length;
    vector<int> node;
    BinaryIndexedTree (int N) : length(N + 1), node(length, 0) {}
    void add(int idx, int val) {
        for (int i = idx; i < length; i += (i & -i)) node[i] += val;
    }
    int getsum(int idx) {
        int ans = 0;
        for (int i = idx; i > 0; i -= (i & -i)) ans += node[i];
        return ans;
    }
};

int main() {
    int N;
    lint K;
    cin >> N >> K;
    vector<lint> a(N);
    rep(i, N) cin >> a[i];
    
    vector<lint> b(N + 1, 0);
    rep(i, N) b[i + 1] = b[i] + a[i];
    rep(i, N + 1) b[i] -= K * i;
    
    vector<pair<lint, int>> c(N + 1);
    rep(i, N + 1) c[i] = pair<lint, int>{b[i], i};
    sort(c.begin(), c.end());
    vector<int> d(N + 1);
    int cnt = 1;
    d[c[0].second] = cnt;
    for (int i = 1; i < N + 1; ++i) {
        if (c[i].first != c[i - 1].first) ++cnt;
        d[c[i].second] = cnt;
    }
    
    BinaryIndexedTree BIT(cnt);
    lint ans = 0;
    rep(i, N + 1) {
        ans += BIT.getsum(d[i]);
        BIT.add(d[i], 1);
    }
    cout << ans << "\n";
    return 0;
}

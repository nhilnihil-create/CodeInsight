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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 3000000000000000000;

struct SegmentTree {
    int length;
    vector<int> node;
    SegmentTree(int N) {
        length = 1;
        while (length < N) length *= 2;
        node.resize(2 * length - 1, inf);
    }
    void update(int idx, int val) {
        idx += (length - 1);
        node[idx] = val;
        while (idx > 0) {
            idx = (idx - 1) / 2;
            node[idx] = min(node[2 * idx + 1], node[2 * idx + 2]);
        }
    }
    int getmin(int a, int b, int now = 0, int l = 0, int r = -1) {
        if (r < 0) r = length;
        if (r <= a || b <= l) return inf;
        if (a <= l && r <= b) return node[now];
        int vl = getmin(a, b, 2 * now + 1, l, (l + r) / 2);
        int vr = getmin(a, b, 2 * now + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};


int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    SegmentTree ST(N);
    rep(i, N) ST.update(i, A[i]);
    
    ll ans = 0;
    rep(i, N) {
        ll x = 0, y = 0;
        int left = -1, right = i + 1;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (ST.getmin(mid, i + 1) < A[i]) left = mid;
            else right = mid;
        }
        x = i - left;
        left = i;
        right = N + 1;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (ST.getmin(i, mid) < A[i]) right = mid;
            else left = mid;
        }
        y = left - i;
        ans += A[i] * x * y;
    }
    cout << ans << "\n";
    return 0;
}

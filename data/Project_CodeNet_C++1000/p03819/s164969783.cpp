#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> P;

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int N, M;
int l[330000], r[330000];
P range[330000];
// Binary Indexed Tree(1-indexed)
const int MAX_N = 110000;

struct BIT {
    int bit[MAX_N + 1], n;

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

signed main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> l[i] >> r[i];
        range[i] = P(l[i], r[i]);
    }
    sort(range, range + N,
         [](P a, P b) { return a.second - a.first < b.second - b.first; });
    BIT bit;
    bit.n = 110000;
    int cur = 0;
    for (int i = 1; i <= M; i++) {
        while (cur < N && i > range[cur].second - range[cur].first) {
            bit.add(range[cur].first + 1, 1);
            bit.add(range[cur].second + 2, -1);
            cur++;
        }
        int ans = N - cur;
        for (int j = 0; j <= M; j += i) {
            ans += bit.sum(j + 1);
        }
        cout << ans << endl;
    }
    return 0;
}
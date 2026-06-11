#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 50;

struct seg {
    int l, r;
};
int n, m;

vector<seg> sgs[N];

struct BIT {
    int n;
    int bit[N];

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

    void add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }

}bit;

int res[N];

int main() {
    cin >> n >> m;
    m++;
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        sgs[r-l+1].push_back({l, r});
    }
    bit.n = m;
    int sumbig = n;
    for(int d = 1; d < m; d++) {
        for(const auto &s : sgs[d]) {
            bit.add(s.l, s.r, 1);
        }
        sumbig -= sgs[d].size();
        for(int j = d; j < m; j += d) {
            res[d] += bit.get(j);
        }
        res[d] += sumbig;
    }
    for(int d = 1; d < m; d++) cout << res[d] << "\n";


}
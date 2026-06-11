#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <numeric>
#include <deque>
#include <limits>
#include <set>
#include <map>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)
#define dump(x) // cerr << __LINE__ << ":\t" #x " = " << x << endl


int n, m;
vector<int> x;
map<int, int> cnt;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (cin >> n >> m) {
        cnt.clear();
        x.resize(n);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            x[i] = a;
            ++cnt[a];
        }
        vector<vector<int>> v(m);
        for (auto &p : cnt) {
            v[p.first % m].push_back(p.second);
        }

        int ans = 0;

        for (int i = 0; i <= m / 2; i++) {
            dump(i);
            if (i == 0 || i == m - i) {
                int add = accumulate(v[i].begin(), v[i].end(), 0) / 2;
                dump(add);
                ans += add;
            } else {
                auto &p = v[i], &q = v[m - i];
                int sp = accumulate(all(p), 0);
                int sq = accumulate(all(q), 0);
                auto &many = sp > sq ? p : q;
                int diff = abs(sp - sq);
                for (auto &x : many) {
                    while (diff >= 1 && x >= 2) {
                        int add = 1;
                        diff -= 2;
                        x -= 2;
                        dump(add);
                        ans += add;
                    }
                }

                int rem_p = 0, rem_q = 0;
                for (auto &x : p) {
                    rem_p += x;
                }
                for (auto &x : q) {
                    rem_q += x;
                }
                int add = min(rem_p, rem_q);
                dump(add);
                ans += add;
            }
        }

        //for (auto &sz : v) {
        //    for (int x : sz) {
        //        ans += x / 2;
        //    }
        //}
            cout << ans << endl;
    }
}
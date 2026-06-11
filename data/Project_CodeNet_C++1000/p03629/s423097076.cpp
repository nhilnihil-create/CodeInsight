#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;
using i64 = int64_t;

string a;
i64 n;
vector<array<i64, 26>> g;
int main() {
    cin >> a;
    n = a.size();
    g = decltype(g)(n + 1);
    for (i64 i = 0; i <= n; ++i) {
        i64 k = a[i - 1] - 'a';
        for (i64 j = i - 1; j >= 0 && g[j][k] == 0; --j) {
            g[j][k] = i;
        }
    }

    queue<i64> q;
    q.push(0);
    vector<i64> p(n + 1, -1);
    while (!q.empty()) {
        i64 u = q.front(); q.pop();
        for (i64 k = 0; k < 26; ++k) {
            i64 v = g[u][k];
            if (v > 0) {
                if (p[v] < 0) {
                    q.push(v);
                    p[v] = u;
                }
            } else {
                string s;
                s.push_back(k + 'a');
                for (i64 v = u; v > 0; v = p[v]) s.push_back(a[v - 1]);
                reverse(begin(s), end(s));
                cout << s << '\n';
                return 0;
            }
        }
    }
    return 0;
}
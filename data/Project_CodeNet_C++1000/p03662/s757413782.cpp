#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

const int Maxn = 100010;
const int INF = (int) 1e6;

int d[2][Maxn];

int n;

vector<int> g[Maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    fill(d[0], d[0] + n, INF);
    fill(d[1], d[1] + n, INF);
    d[0][0] = 0, d[1][n - 1] = 0;

    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (auto &c : g[p]) {
            if (d[0][c] == INF) {
                d[0][c] = d[0][p] + 1;
                que.push(c);
            }
        }
    }

    que.push(n - 1);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        for (auto &c : g[p]) {
            if (d[1][c] == INF) {
                d[1][c] = d[1][p] + 1;
                que.push(c);
            }
        }
    }

    int cnt_f = 0, cnt_s = 0;
    for (int i = 0; i < n; ++i) {
        if (d[0][i] <= d[1][i]) cnt_f++;
        else cnt_s++;
    }
    if (cnt_f > cnt_s) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}

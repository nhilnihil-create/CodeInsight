#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;
const int N = 100100;

vector<int> g[N];

int way[N], used[N];
int t[3];

void dfs(int v) {
    for (int u : g[v]) {
        if (way[u] == 0) {
            way[u] = v;
            dfs(u);
        }
    }
}

void cnt(int v) {
    ++t[used[v]];
    for (int u : g[v]) {
        if (!used[u]) {
            used[u] = used[v];
            cnt(u);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    way[1] = -1;
    dfs(1);
    vector<int> order;
    for (int v = n; v != -1; v = way[v]) {
        order.push_back(v);
    }
    int m = order.size();
    used[order[m / 2 - 1]] = 2;
    used[order[m / 2]] = 1;
    cnt(order[m / 2 - 1]);
    cnt(order[m / 2]);
    if (t[1] > t[2]) {
        cout << "Fennec";
    } else {
        cout << "Snuke";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pair<int, int>> orders(n+1);
    for (int i = 0; i <= n; ++i) {
        orders[i] = { 1e9, i };
    }
    vector<bool> reached(n+1);
    int start = 1;
    int goal = g[start][0];
    reached[start] = true;
    reached[goal] = true;
    orders[start].first = 0;
    orders[goal].first = 1;
    int count = 2;
    while (1) {
        bool finished = true;
        for (int v : g[start]) {
            if (!reached[v]) {
                finished = false;
                reached[v] = true;
                orders[v].first = orders[start].first - 1;
                start = v;
                count++;
                break;
            }
        }
        for (int v : g[goal]) {
            if (!reached[v]) {
                finished = false;
                reached[v] = true;
                orders[v].first = orders[goal].first + 1;
                goal = v;
                count++;
                break;
            }
        }
        if (finished) {
            break;
        }
    }
    sort(orders.begin(), orders.end());
    cout << count << endl;
    for (int i = 0; i < count; ++i) {
        cout << orders[i].second << ' ';
    }
    return 0;
}

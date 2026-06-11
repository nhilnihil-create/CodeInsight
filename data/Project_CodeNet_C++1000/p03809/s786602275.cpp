#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int N;
int A[100000];
int ch[100000] = {};
bool used[100000] = {};
vector<int> G[100000];

int dfs(int v) {
    used[v] = true;
    if (G[v].size() == 1) {
        ch[v] = A[v];
    }
    int max_ch = 0;
    for (int i = 0; i < G[v].size(); i++) {
        if (!used[G[v][i]]) {
            int cur_ch = dfs(G[v][i]);
            ch[v] += cur_ch;
            max_ch = max(max_ch, cur_ch);
        }
    }
    if (v != 0 && G[v].size() >= 3 && ch[v] - A[v] > ch[v] - max_ch) {
        return ch[v] = -1;
    }
    if ((v != 0 && G[v].size() == 2 && ch[v] != A[v]) || A[v] > ch[v]) {
        return ch[v] = -1;
    }
    return ch[v] = 2 * A[v] - ch[v];
}

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    if (dfs(0) != 0) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (ch[i] < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

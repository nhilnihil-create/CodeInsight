#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[100005];
int cnt = 0;
vector<int> G[100005];

int dfs(int v, int depth = 0) {
        int ret = 1;
        for (auto &u : G[v]) {
                if (u != 1) ret = max(ret, dfs(u, depth + 1) + 1);
        }
        if (depth > 1 && ret == K) {
                cnt++;
                ret = 0;
        }
        return (ret);
}

int main() {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
                cin >> A[i];
                G[A[i]].push_back(i);
        }
        if (A[1] != 1) cnt++;
        dfs(1);
        cout << cnt << endl;
        return (0);
}

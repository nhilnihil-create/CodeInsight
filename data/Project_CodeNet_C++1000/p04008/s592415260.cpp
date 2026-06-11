#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K;
int ans = 0;

vector<vector<int>> edge;

int dfs(int now, int pre) {
    int height = 0;
    for (int nxt : edge[now]) {
        height = max(height, dfs(nxt, now));
    }
    if (height == K-1 && pre != 1 && pre != 0) {
        ans++;
        return 0;
    }
    if (height == K && pre == 1) {
        ans++;
        return 0;
    }
    return height+1;
}

int main() {
    cin >> N >> K;
    edge.resize(N+1);
    vector<int> A(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (i >= 2) edge[A[i]].push_back(i);
    }
    if (A[1] != 1) ans++;
    
    dfs(1, 0);
    
    cout << ans << endl;
    
    return 0;
}

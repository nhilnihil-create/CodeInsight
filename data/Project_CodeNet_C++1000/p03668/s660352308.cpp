#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> edge;
vector<int> grundy;

void dfs(int now, int par) {
    for (int child : edge[now]) {
        if (child != par) {
            dfs(child, now);
            grundy[now] ^= grundy[child]+1;
        }
    }
    return;
}

int main(){
    int N;
    cin >> N;
    edge.resize(N+1);
    grundy = vector<int>(N+1, 0);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1, 0);
    if (grundy[1] == 0) cout << "Bob\n";
    else cout << "Alice\n";
    return 0;
}
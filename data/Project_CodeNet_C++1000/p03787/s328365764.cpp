#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--;B--;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }
    
    vector<bool> visited(N, false);
    ll bip = 0, unbip = 0;
    vector<int> color(N, 0);
    ll point = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        if (edge[i].empty()) {
            point++;
            visited[i] = true;
            continue;
        }
        queue<int> q;
        bool isbip = true;
        q.push(i);
        color[i] = 1;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int nxt : edge[now]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.push(nxt);
                    color[nxt] = 3-color[now];
                }else {
                    if (color[nxt] == color[now]) {
                        isbip = false;
                    }
                }
            }
        }
        if (isbip) bip++;
        else unbip++;
    }
    
    cout << bip*bip*2 + unbip*unbip + bip*unbip*2 + N*point*2 - point*point << endl;
    return 0;
}
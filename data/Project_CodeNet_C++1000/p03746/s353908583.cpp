#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N+1, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<bool> visited(N+1, false);
    visited[1] = true;
    visited[edge[1][0]] = true;
    vector<int> lroute, rroute;
    lroute.push_back(1);
    rroute.push_back(edge[1][0]);
    
    int now = 1;
    for (int z = 0; z < N; z++) {
        bool stop = true;
        for (int nxt : edge[now]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                lroute.push_back(nxt);
                now = nxt;
                stop = false;
                break;
            }
        }
        if (stop) break;
    }
    
    now = edge[1][0];
    for (int z = 0; z < N; z++) {
        bool stop = true;
        for (int nxt : edge[now]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                rroute.push_back(nxt);
                now = nxt;
                stop = false;
                break;
            }
        }
        if (stop) break;
    }
    
    printf("%d\n", (int)lroute.size()+(int)rroute.size());
    for (int i = 0; i < (int)lroute.size(); i++) {
        if (i == 0) printf("%d", lroute[lroute.size()-1-i]);
        else printf(" %d", lroute[lroute.size()-1-i]);
    }
    for (int i = 0; i < (int)rroute.size(); i++) {
        printf(" %d", rroute[i]);
    }
    printf("\n");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define INF 1001001001
#define MAX_V 100000
typedef pair<int,int> P;

int N;
vector<int> G[MAX_V];
int d[2][MAX_V];

void dijkstra(int s, int t) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d[t], d[t]+N, INF);
    d[t][s] = 0;
    que.push(P(0,s));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[t][v] < p.first) continue;
        for(int i=0; i < G[v].size(); i++) {
            int e = G[v][i];
            if(d[t][e] > d[t][v] + 1) {
                d[t][e] = d[t][v] + 1;
                que.push(P(d[t][e], e));
            }
        }
    }
}

int main() {
    cin >> N;
    for(int i=0; i<N-1; ++i) {
        int a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    dijkstra(0,0);
    dijkstra(N-1,1);

    int fcnt = 0;
    for(int i=0; i<N; ++i) {
        if(d[0][i] <= d[1][i]) ++fcnt;
    }
    if(fcnt > N / 2) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}
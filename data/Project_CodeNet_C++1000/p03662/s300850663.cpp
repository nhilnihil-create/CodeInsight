#include<bits/stdc++.h>
using namespace std;

#define WHITE -1
#define BLACK 1


const int MAX = 100005;
vector<int> A[MAX];
int color[MAX];


void bfs(int u, int v) {
    queue<int> qf, qs;
    qf.push(u);
    qs.push(v);
    int s, t;
    int p;
    int m;
    while (!qf.empty() || !qs.empty()) {
        m = qf.size();
        for (int j = 0; j < m; j++) {
            s = qf.front(); qf.pop();
            for (int i = 0; i < A[s].size(); i++) {
                p = A[s][i];
                if (color[p] == BLACK || color[p] == WHITE) continue;
                color[p] = WHITE;
                qf.push(p);
            }
        }
        m = qs.size();
        for (int j = 0; j < m; j++) {
            t = qs.front(); qs.pop();
            for (int i = 0; i < A[t].size(); i++) {
                p = A[t][i];
                if (color[p] == BLACK || color[p] == WHITE) continue;
                color[p] = BLACK;
                qs.push(p);
            }
        }
    }
}

int main() {
    int N, a, b;
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    
    for (int i = 0; i < N; i++) color[i] = 0;
    color[0] = WHITE;
    color[N-1] = BLACK;

    bfs(0, N-1);
    int fen, snu;
    fen = snu = 0;
    for (int i = 0; i < N; i++) {
        if (color[i] == WHITE) fen++;
        else snu++;
    }

    if (fen > snu) printf("Fennec\n");
    else printf("Snuke\n");
    
    return 0;
}


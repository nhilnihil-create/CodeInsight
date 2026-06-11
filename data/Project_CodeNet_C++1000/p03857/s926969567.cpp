#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

vector<int> par[2];
vector<int> rnk[2];

void makeSets(int n, int d) {
    par[d].resize(n);
    rnk[d].resize(n);
    for(int i=0; i<n; i++) {
        par[d][i] = i;
        rnk[d][i] = 0;
    }
}

int find(int x, int d) {
    if(x != par[d][x]) par[d][x] = find(par[d][x], d);
    return par[d][x];
}

void unite(int xp, int yp, int d) {
    int x = find(xp, d);
    int y = find(yp, d);
    if(x == y) return;
    if(rnk[d][x] > rnk[d][y]) par[d][y] = x;
    else par[d][x] = y;
    if(rnk[d][x] == rnk[d][y]) rnk[d][y]++;
}

int main() {
    int N, K, L;
    cin >> N >> K >> L;
    
    for(int d=0; d<2; ++d) makeSets(N, d);

    for(int i=0; i<K+L; ++i) {
        int p,q;
        cin >> p >> q;
        --p; --q;
        if(i < K) unite(p, q, 0);
        else unite(p, q, 1);
    }

    map<pp, int> G;
    for(int i=0; i<N; ++i) {
        G[pp(find(i,0), find(i,1))] += 1;
    }
    
    for(int i=0; i<N; ++i) {
        cout << G[pp(find(i,0), find(i,1))] << (i+1<N ? ' ' : '\n');
    }
    return 0;
}
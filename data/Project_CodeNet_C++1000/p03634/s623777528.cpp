#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct edge {
    int to, cost;
};

const int N=1e5+5;
int n;
vector<edge> G[N];
int parent[N];
LL depth[N];

void go( int v, int p, LL d ) {
    parent[v]=p;
    depth[v]=d;
    for ( auto e:G[v] ) {
        int u=e.to,w=e.cost;
        if ( u==p ) continue;
        go(u,v,d+w);
    }
}

int main() {
    cin >> n;
    for ( int i=0; i<n-1; i++ ) {
        int a,b,c;
        cin >> a >> b >> c;
        --a; --b;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    int q,k;
    cin >> q >> k;
    --k;
    go(k,-1,0);
    while ( q-- ) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        cout << abs(depth[a]+depth[b]) << '\n';
    }
    return 0;
}

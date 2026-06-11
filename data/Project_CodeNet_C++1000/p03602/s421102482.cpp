#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) {if(a<b) {a=b;return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if(a>b) {a=b;return true;} return false;}
const ll INF = 1LL<<60;

class UnionFind {
public:
    std::vector<int> data;
    UnionFind( int n ) {
        data.resize( n, -1 );
    }
    int find( int x ) {
        if ( data[x] < 0 ) {
            return x;
        } else {
            int r = find( data[x] );
            data[x] = r;
            return r;
        }
    }
    void unite( int x, int y ) {
        int r = find( x );
        int s = find( y );
        if ( r != s ) {
            data[r] += data[s];
            data[s] = r;
        }
    }
};

struct Edge {
    int to;
    ll dist;
};

ll solve() {
    ll N;
    cin >> N;
    vector<vector<ll>> A(N,vector<ll>(N));
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            cin >> A[i][j];
        }
    }
    auto cmp = [&](pii& i1, pii& i2) { 
        return A[i1.first][i1.second] > A[i2.first][i2.second];
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);
    for ( int i = 0; i < N; i++ ) {
        for ( int j = i+1; j < N; j++ ) {
            q.push(pii(i,j));
        }
    }

    vector<vector<Edge>> G(N);
    UnionFind uf(N);

    auto cmpD = [&](pair<ll,int>& i1, pair<ll,int>& i2) { 
        return i1.first > i2.first;
    };
    auto dijkstra = [&](int s, int f) -> ll {
        vector<ll> dist(N,INF);
        dist[s] = 0;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, decltype(cmpD)> qD(cmpD);
        qD.push(make_pair(dist[s], s));
        while ( !qD.empty() ) {
            ll d = qD.top().first;
            int v = qD.top().second;
            if ( v == f ) return d;
            qD.pop();
            if ( d > dist[v] ) continue;
            for ( auto e : G[v] ) {
                ll dn = dist[v] + e.dist;
                if ( chmin( dist[e.to], dn ) ) {
                    qD.push(make_pair(dn, e.to));
                }
            }
        }
        return INF;
    };

    while ( !q.empty() ) {
        auto p = q.top();
        q.pop();
        bool addEdge = false;
        if ( uf.find(p.first) != uf.find(p.second) ) {
            addEdge = true;
            uf.unite(p.first,p.second);
        } else {
            ll dd = dijkstra(p.first,p.second);
            if ( dd < A[p.first][p.second] ) {
                return -1;
            } else if ( dd > A[p.first][p.second] ) {
                addEdge = true;
            }
        }
        if ( addEdge ) {
            G[p.first].push_back(Edge{p.second,A[p.first][p.second]});
            G[p.second].push_back(Edge{p.first,A[p.first][p.second]});
        }
    }

    ll ans = 0;
    for ( int i = 0; i < N; i++ ) {
        for ( auto e : G[i] ) {
            ans += e.dist;
        }
    }
    ans /= 2;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}
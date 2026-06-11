#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


void solve(int N, int M, vi& a, vi& b, int Q, vi& v, vi& d, vi& c){
    vi masks(11, 0);
    rep(d,11) {
        masks[d] = (1 << (d+1))-1;
    }

    vvi ne(N);
    rep(i,M) {
        int ai = a[i], bi = b[i];
        ne[ai].pb(bi);
        ne[bi].pb(ai);
    }

    vi visited(N, 0);
    vi colors(N, 0);

    queue<ii> q;
    for (int i=Q-1; i>=0; --i) {
        int v0 = v[i], d0 = d[i], c0 = c[i];

        if (visited[v0] & (1 << d0)) continue;

        if (visited[v0] == 0) colors[v0] = c0;
        visited[v0] |= masks[d0];

        if (d0 == 0) continue;
        --d0;

        for (int u: ne[v0]) {
            q.emplace( u, d0 );
        }
        while (!q.empty()) {
            int u=q.front().first, d=q.front().second;
            q.pop();

            if (visited[u] & (1 << d)) continue;
            if (visited[u] == 0) colors[u] = c0;
            visited[u] |= masks[d];
            if (d == 0) continue;
            --d;

            for (int v: ne[u]) {
                if (visited[v] & (1 << d)) continue;
                q.emplace( v, d );
            }

        }
    }

    rep(i,N) {
        printf("%d\n", colors[i]);
    }
}

int main() {
    int N, M; scanf("%d %d", &N, &M);
    vi a(M), b(M);
    rep(i,M){
        scanf("%d %d", &a[i], &b[i]);
        --a[i]; --b[i];
    }
    int Q; scanf("%d", &Q);
    vi v(Q),d(Q),c(Q);
    rep(i,Q){
        scanf("%d %d %d", &v[i], &d[i], &c[i]);
        --v[i];
    }
    solve(N,M,a,b, Q,v,d,c);
    return 0;
}

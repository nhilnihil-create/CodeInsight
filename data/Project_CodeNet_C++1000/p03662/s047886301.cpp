#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
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

vi d_from(int from, vvi& nx) {
    int N = nx.size();
    vi dst(N, N+1);
    queue<ii> q; q.push(ii(0, from));
    while (!q.empty()) {
        ii t = q.front(); q.pop();
        int d = t.first, u = t.second;
        if (dst[u] <= d) continue;
        dst[u] = d;
        for (int v: nx[u]) {
            if (dst[v] <= d+1) continue;
            q.push(ii(d+1, v));
        }
    }
    // cerr << from << " " << dst << endl;
    return dst;
}

bool solve(int N, vi& a, vi& b) {
    vvi nx(N);
    rep(i,N-1){
        nx[a[i]].pb(b[i]);
        nx[b[i]].pb(a[i]);
    }

    vi da = d_from(0, nx), db = d_from(N-1, nx);

    int fennec=0, snuke=0;
    rep(i,N){
        if (da[i] <= db[i]) ++fennec;
        else ++snuke;
    }
    return (fennec > snuke);
}

int main() {
    int N; cin >> N;
    vi a(N-1), b(N-1);
    rep(i,N-1) {
        cin >> a[i] >> b[i]; --a[i]; --b[i];
    }
    cout << (solve(N,a,b) ? "Fennec":"Snuke") << endl;
    return 0;
}

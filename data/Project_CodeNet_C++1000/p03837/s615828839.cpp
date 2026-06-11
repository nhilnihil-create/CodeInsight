#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
// const long long INF = 1LL<<60;
const int INF = 1<<29;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int main() {
    int N,M;cin>>N>>M;
    vector<int> a(M,0),b(M,0),c(M,0);
    vector<vector<int>> dist(N,vector<int>(N,INF)); 
    rep(i,N) dist[i][i] = 0;
    rep(i,M) {
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;b[i]--;
        dist[a[i]][b[i]] = c[i];
        dist[b[i]][a[i]] = c[i];
    }
    rep(k,N) rep(i,N) rep(j,N) {
        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    }
    int ans = 0;
    rep(i,M) {
        if(c[i] != dist[a[i]][b[i]]) ans++;
    }
    cout<<ans<<endl;
}
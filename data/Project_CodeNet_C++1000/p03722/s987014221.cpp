#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
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
    // vector<vector<P>> g(N,vector<P>());
    vector<ll> dist(N,INF);
    vector<int> a(M,0),b(M,0);
    vector<ll> c(M,0);
    rep(i,M) {
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;b[i]--;
        c[i] = -c[i];
        // g[a].push_back(P(b,-c));
    }
    dist[0] = 0;
    rep(i,N) {
        rep(j,M) {
            if(dist[b[j]] > dist[a[j]] + c[j]) {
                if(i==N-1 && b[j]==N-1) {
                    cout<<"inf"<<endl;
                    return 0;
                }
                dist[b[j]] = dist[a[j]] + c[j];
            }
        }
    }
    cout<<-dist[N-1]<<endl;
}
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define pb push_back
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef vector<vector<P>> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<ll> vec;
const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
const int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30);
const int INF = (1LL << 60);
const double EPS = (1 >> 30);
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n,m,R;
    cin>>n>>m>>R;
    vector<int> r(R);
    REP(i,R) cin >> r[i];
    sort(all(r));
    vector<int> dist[n];
    REP(i,n) dist[i].assign(n,INF);
    
    REP(i,n) dist[i][i] = 0;

    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        dist[a][b]=c;
        dist[b][a]=c;
    }
    
    REP(k,n){
      REP(i,n){
        REP(j,n){
          dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
        }
      }
    }

    int g=1;
    rep(i,R+1){
        if(i==0) continue;
        g*=i;
    }
    ll ans=INF;
    rep(i,g){
        ll fg=0;
        rep(j,R-1){
            fg+=dist[r[j]-1][r[j+1]-1];
        }
        chmin(ans,fg);
        next_permutation(all(r));
    }
    cout<<ans<<endl;

    
}
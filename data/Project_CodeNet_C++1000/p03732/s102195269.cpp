//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll INF = 1000000007;
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
// chmax chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    int N;
    ll W;
    cin >> N >> W;
    ll v[N], w[N];
    REP(i,N) cin >> w[i] >> v[i];

    ll dp[N+1][N+1][3*N];
    REP(i,N+1)REP(j,N+1)REP(k,3*N) dp[i][j][k] = 0;

    ll ans = 0;
    for(ll i=1; i<N+1; i++)for(ll j=1; j<N+1; j++)for(ll k=0; k<3*N; k++){
        if(k-(w[i-1]-w[0]) >= 0) chmax(dp[i][j][k], dp[i-1][j-1][k-(w[i-1]-w[0])]+v[i-1]);
        chmax(dp[i][j][k], dp[i-1][j][k]);
        if((ll)j*w[0]+k <= W) chmax(ans, dp[i][j][k]);
    }

    cout << ans << endl;

    return 0;
}
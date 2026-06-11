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
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define INF (ll)1000000007
// chmax chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){

    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    ll a[N], b[N], c[N];
    ll amax = 0, bmax = 0;
    REP(i,N){
        cin >> a[i] >> b[i] >> c[i];
        amax += a[i];
        bmax += b[i];
    }

    ll dp[N+1][amax+1][bmax+1];
    REP(i,N+1)REP(j,amax+1)REP(k,bmax+1){
        dp[i][j][k] = INF;
    }
    REP(i,N+1) dp[i][0][0] = 0;

    FOR(i,1,N+1)FOR(j,1,amax+1)FOR(k,1,bmax+1){
        if(j-a[i-1] >= 0 && k-b[i-1] >= 0) chmin(dp[i][j][k], dp[i-1][j-a[i-1]][k-b[i-1]]+c[i-1]);
        chmin(dp[i][j][k], dp[i-1][j][k]);
    }

    ll ans = INF;
    int ma = Ma, mb = Mb;
    while(ma <= amax && mb <= bmax){
        chmin(ans, dp[N][ma][mb]);
        ma += Ma; mb += Mb;
    }

    if(ans == INF) ans = -1;

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define INF (ll)1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
int main(void){
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    REP(i,N) cin >> a[i];
    SORT(a);
 
    int l=-1, r=N, n=(l+r)/2;
 
    while(r-l > 1){
        int dp[N][K+1];
        REP(i,N)REP(j,K+1) dp[i][j] = 0;
        REP(i,N) dp[i][0] = 1;
        int k=1;
        REP(i,N){
            if(i == n) continue;
            FOR(j,1,K+1){
                if(j-a[i] >= 0) chmax(dp[k][j], dp[k-1][j-a[i]]);
                chmax(dp[k][j], dp[k-1][j]);
            }
            k++;
        }
        bool flag = false;
        for(ll i=max((ll)0, (ll)K-a[n]); i<K; i++) if(dp[N-1][i]){flag = true; break;}
        if(flag) r = n;
        else l = n;
        n = (l+r)/2;
    }
 
    cout << l+1 << endl;
    
    return 0;
}
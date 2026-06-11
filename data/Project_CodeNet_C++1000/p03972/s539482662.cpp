#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef vector<string> VS;
typedef pair<ll, ll> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int INF = 2147483647;
const long long LINF = 1LL<<60;
const long long MOD = 1000000007; // 998244353

#define CLR(a) memset((a), 0, sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    ll W,H; cin >> W >> H;
    VL p(W), q(H); REP(i,W) cin >> p[i]; REP(i,H) cin >> q[i];
    priority_queue<P,vector<P>,greater<P>> que;
    REP(i,W) que.push(P(p[i],0));
    REP(i,H) que.push(P(q[i],1));

    ll ans = 0;
    ll mx = (H+1)*(W+1) - 1, nx = 0, ny = 0;
    while(mx > 0){
        P a = que.top(); que.pop();
        ll cost = a.first;
        if(a.second){
            ans += cost * (W+1 - nx);
            ny++;
            mx -= W+1 - nx;
        }
        else{
            ans += cost * (H+1 - ny);
            nx++;
            mx -= H+1 - ny;
        }
    }
    cout << ans << endl;
    return 0;
}
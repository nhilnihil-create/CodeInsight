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
typedef pair<int, int> P;
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
    int N,M; cin >> N >> M;
    VI X(N); REP(i,N) cin >> X[i];
    VI num(100001,0), mod(M,0), p(M,0);
    REP(i,N){
        num[X[i]]++;
        mod[X[i]%M]++;
    }
    REP(i,100001) p[i%M] += num[i]/2;
    int ans = mod[0]/2;
    FOR(i,1,(M-1)/2+1){
        if(mod[i] > mod[M-i]){
            ans += mod[M-i];
            int res = mod[i] - mod[M-i];
            ans += min(res/2, p[i]);
        }
        else{
            ans += mod[i];
            int res = mod[M-i] - mod[i];
            ans += min(res/2, p[M-i]);
        }
    }
    if(M%2 == 0) ans += mod[M/2]/2;
    cout << ans << endl;
    return 0;
}
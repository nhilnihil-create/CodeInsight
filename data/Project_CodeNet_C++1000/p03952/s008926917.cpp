#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
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
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007; // 998244353

#define CLR(a) memset((a), 0, sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    int N,x; cin >> N >> x;
    if(x == 1 || x == 2*N-1){
        cout << "No" << endl;
        return 0;
    }
    else if(N == 2){
        cout << "Yes" << endl;
        cout << 1 << en << 2 << en << 3 << endl;
        return 0;
    }
    cout << "Yes" << endl;
    VI ans(2*N-1);
    if(x != 2){
        ans[N-2] = x-1; ans[N-1] = x; ans[N] = x+1; ans[N+1] = x-2;
        int n = 1;
        REP(i,N-2){
            while(x-2<=n && n<=x+1) n++;
            ans[i] = n++;
        }
        FOR(i,N+2,2*N-1){
            while(x-2<=n && n<=x+1) n++;
            ans[i] = n++;
        }
    }
    else{
        ans[N-2] = x+1; ans[N-1] = x; ans[N] = x-1; ans[N+1] = x+2;
        int n = 1;
        REP(i,N-2){
            while(x-1<=n && n<=x+2) n++;
            ans[i] = n++;
        }
        FOR(i,N+2,2*N-1){
            while(x-1<=n && n<=x+2) n++;
            ans[i] = n++;
        }
    }
    REP(i,2*N-1) cout << ans[i] << en;
    return 0;
}
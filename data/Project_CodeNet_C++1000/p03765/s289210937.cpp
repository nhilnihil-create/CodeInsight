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

constexpr double EPS = 1e-9;
constexpr double PI  = 3.141592653589793238462643383279;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    string S,T; cin >> S >> T;
    int NS = S.size(), NT = T.size();
    VI SA(NS+1,0), SB(NS+1,0), TA(NT+1,0), TB(NT+1,0);
    REP(i,NS){
        if(S[i] == 'A') SA[i+1] = 1;
        else SB[i+1] = 1;
    }
    REP(i,NS){
        SA[i+1] += SA[i];
        SB[i+1] += SB[i];
    }
    REP(i,NT){
        if(T[i] == 'A') TA[i+1] = 1;
        else TB[i+1] = 1;
    }
    REP(i,NT){
        TA[i+1] += TA[i];
        TB[i+1] += TB[i];
    }

    int q; cin >> q;
    REP(i,q){
        int a,b,c,d; cin >> a >> b >> c >> d;
        int sa = SA[b] - SA[a-1], sb = SB[b] - SB[a-1];
        int ta = TA[d] - TA[c-1], tb = TB[d] - TB[c-1];
        if(sa < ta) tb += 2*(ta-sa);
        else sb += 2*(sa-ta);

        cout << (abs(sb-tb)%3 == 0 ? "YES" : "NO") << en;
    }
    return 0;
}
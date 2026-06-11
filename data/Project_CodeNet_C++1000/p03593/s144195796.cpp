#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    int H,W; cin >> H >> W;
    VI use(26,0);
    REP(i,H*W){
        char c; cin >> c;
        use[c-'a']++;
    }

    int n = 0;
    REP(i,26){
        if(n < (H/2)*(W/2) && use[i]>=4){
            int tmp = min((H/2)*(W/2)-n, use[i]/4);
            n += tmp;
            use[i] -= tmp*4;
        }
    }
    if(n < (H/2)*(W/2)){
        cout << "No" << endl;
        return 0;
    }
    if(H%2){
        n = 0;
        REP(i,26){
            if(n < W/2 && use[i]>=2){
                int tmp = min(W/2-n, use[i]/2);
                n += tmp;
                use[i] -= tmp*2;
            }
        }
        if(n < W/2){
            cout << "No" << endl;
            return 0;
        }
    }
    if(W%2){
        n = 0;
        REP(i,26){
            if(n < H/2 && use[i]>=2){
                int tmp = min(H/2-n, use[i]/2);
                n += tmp;
                use[i] -= tmp*2;
            }
        }
        if(n < H/2){
            cout << "No" << endl;
            return 0;
        }
    }
    if(H%2 && W%2){
        n = 0;
        REP(i,26){
            if(use[i]%2){
                use[i] -= 1;
                n = 1;
                break;
            }
        }
        if(n < 1){
            cout << "No" << endl;
            return 0;
        }
    }
    int sum = 0;
    REP(i,26) sum += use[i];
    cout << (sum==0 ? "Yes" : "No") << endl;
    return 0;
}
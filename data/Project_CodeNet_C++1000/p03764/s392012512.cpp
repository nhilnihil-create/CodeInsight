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

long long modp(long long a, long long p) {
    long long res = a % p;
    if (res < 0) res += p;
    return res;
}

long long dif_modp(long long a, long long b, long long p){
    // a-b mod p
    return modp(a % p - b % p, p);
}

int main(void){
    int N,M;
    cin >> N >> M;
    ll x[N], y[M];
    REP(i,N) cin >> x[i];
    REP(i,M) cin >> y[i];

    ll Xsum = 0, Ysum = 0;
    REP(i,N) Xsum = (Xsum + dif_modp((i*x[i])%INF, ((N-1-i)*x[i])%INF, INF))%INF;
    REP(i,M) Ysum = (Ysum + dif_modp((i*y[i])%INF, ((M-1-i)*y[i])%INF, INF))%INF;
    cout << (Xsum*Ysum)%INF << endl;
    return 0;
}
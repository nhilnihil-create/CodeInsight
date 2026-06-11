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
const long long INF = 1000000007;
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
// chmax chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

long long mul_modp(long long a, long long b, long long p){
    // a*b mod p
    return ((a % p) * (b % p)) % p;
}

int main(void){
    int N; cin >> N;
    string s1,s2; cin >> s1 >> s2;

    ll ans;
    int init, ptn;
    if(s1[0] == s2[0]){ans = 3; init=1; ptn=0;}
    else{ans = 6; init=2; ptn=1;}

    FOR(i,init,N){
        if(s1[i] == s2[i]){
            if(ptn) ans = mul_modp(ans, 1, INF);
            else ans = mul_modp(ans, 2, INF);
            ptn = 0;
        }
        else{
            if(ptn) ans = mul_modp(ans, 3, INF);
            else ans = mul_modp(ans, 2, INF);
            ptn = 1;
            i++;
        }
    }
    cout << ans << endl;

    return 0;
}
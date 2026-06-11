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

vector<vector<long long>> comb(int n) {
    vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}

int main(void){

    int N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    REP(i,N) cin >> v[i];
    SORT(v);

    ll sum = 0;
    REP(i,A) sum += v[N-1-i];
    double ave = (double)sum / A;

    int num1 = 0, num2 = 0;
    while(N-A-num1-1 >= 0 && v[N-A-num1-1] == v[N-A]) num1++;
    while(N-A+num2 < N && v[N-A] == v[N-A+num2]) num2++;
    int num = num1 + num2;

    vector<vector<ll>> ncr = comb(num);
    ll ans = 0;
    if(v[N-A] == v[N-1]) REP(i, min(B-A,num1)+1) ans += ncr[num][A+i];
    else ans = ncr[num][num2];

    cout << fixed;
    cout << setprecision(8) << ave << endl;
    cout << ans << endl;

    return 0;
}
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
#define EXIST(m,v) (m).find((v)) != (m).end()
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void Main(){
    int n,m; cin >> n >> m;
    VI a(n); REP(i,n) cin >> a[i];
    VL s(m+1,0), e(m+1,0);
    REP(i,n-1) s[a[i]]++;
    REP(i,n-1){
        if(a[i]<a[i+1]) e[a[i+1]] += a[i+1]-a[i]-1;
        else{
            e[a[i+1]] += m-a[i];
            e[a[i+1]] += a[i+1]-1;
        }
    }

    VL p(m+1,0), q(m+1,0);
    REP(i,n-1){
        if(a[i]<m && a[i+1]<a[i]) p[m]++;
        if(a[i+1] == m) q[m] += e[m];
    }
    RFOR(i,m,1){
        p[i] = p[i+1] + s[i+1];
        if(i == a[n-1]-1) p[i]++;
        if(i == a[0]-1) p[i]--;
        p[i] -= s[i];
        q[i] = e[i];
    }

    ll ans = 0;
    REP(i,n-1){
        if(a[i+1] == m) ans += 1;
        else if(a[i]<a[i+1]) ans += a[i+1]-a[i];
        else if(a[i]==m) ans += a[i+1];
        else ans += a[i+1]+1;
    }

    ll tmp = ans;
    REP(i,m-1){
        tmp += p[m-1-i];
        tmp -= q[m-1-i];
        chmin(ans, tmp);
    }

    cout << ans << en;
    return;
}

int main(void){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t) Main();
    return 0;
}
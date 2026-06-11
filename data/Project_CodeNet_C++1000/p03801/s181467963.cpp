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

constexpr double EPS = 1e-9;
constexpr double PI  = 3.141592653589793238462643383279;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

bool comp(P a, P b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

int main(void){
    int N; cin >> N;
    VL a(N); REP(i,N) cin >> a[i];
    vector<P> v(N);
    REP(i,N){
        v[i].first = a[i];
        v[i].second = i;
    }
    sort(ALL(v), comp);

    VL ans(N,0);
    ll idx = 0, prev = 0;
    ll sum = 0;
    while(idx<N){
        while(idx<N-1 && v[prev].second < v[idx+1].second){
            sum += v[idx].first;
            idx++;
        }
        sum += v[idx].first;
        idx++;
        ll t = idx==N ? 0 : v[idx].first;
        ans[v[prev].second] = sum - idx*t;
        sum -= sum - idx*t;
        prev = idx;
    }

    REP(i,N) cout << ans[i] << en;

    return 0;
}
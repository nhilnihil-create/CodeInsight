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

long long modp(long long a, long long p) {
    long long res = a % p;
    if (res < 0) res += p;
    return res;
}

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    return a.second < b.second;
}

int main(void){
    ll N,L,T; cin >> N >> L >> T;
    vector<ll> X(N), W(N); REP(i,N) cin >> X[i] >> W[i];

    ll n_swap = 0;
    REP(i,N-1){
        if(W[0] == W[i+1]) continue;
        if(W[0] == 1) n_swap += (2*T + (L-X[i+1]+X[0])) / L;
        else n_swap += (2*T + (X[i+1]-X[0])) / L;
    }

    ll init;
    if(W[0] == 1) init=-1;
    else init=LL_INF;
    vector<pair<ll,ll>> after(N, pair<ll,ll>(0,init));
    if(W[0] == 1) after[0].second = modp(n_swap, N);
    else after[0].second = modp(-n_swap, N);

    ll key = after[0].second;

    REP(i,N){
        if(W[i] == 1) after[i].first = modp(X[i]+T, L);
        else after[i].first = modp(X[i]-T, L);
    }

    SORT(after);

    int pos = 0; while(after[pos].second != key) pos++;
    REP(i,N){
        after[pos].second = key;
        pos = (pos+1)%N;
        key = (key+1)%N;
    }

    sort(after.begin(), after.end(), comp);

    REP(i,N) cout << after[i].first << endl;
    return 0;
}
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

vector<int> compress(vector<int> &v){
    int N = v.size(), mn = 1000000000;
    vector<int> res(N);
    vector<pair<int,int>> a(N);
    for(int i=0; i<N; ++i){
        a[i].first = v[i];
        a[i].second = i;
        mn = min(mn, v[i]);
    }
    sort(a.begin(), a.end());
    
    int prev = mn-1, n = -1;
    for(int i=0; i<N; ++i){
        if(a[i].first == prev) res[a[i].second] = n;
        else{
            n++;
            prev = a[i].first;
            res[a[i].second] = n;
        }
    }
    
    return res;
}

int main(void){
    int N; cin >> N;
    VI A(N); REP(i,N) cin >> A[i];
    A = compress(A);
    int ans = 0;
    REP(i,N/2) if(A[2*i+1]%2 == 0) ans++;
    cout << ans << endl;
    return 0;
}
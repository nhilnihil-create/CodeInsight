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
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<class T>
void remove_duplication(vector<T> &v){
    sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

template<typename T>
struct BIT{
    private:
        using Func = function<T(T, T)>;

        int n;
        vector<T> node;

        T init_v;
        Func func;

    public:

        BIT(int N, Func _func, T _init_v) {
            n = N + 1;
            init_v = _init_v;
            func = _func;

            node.resize(n, init_v);
            for(int i=1; i<n; i++) if((i+(i&-i)) < n) node[i+(i&-i)] = func(node[i+(i&-i)], node[i]);
        }

        BIT() {}

        void add(int pos, T v) {
            // 1-indexed
            while(pos < n){
                node[pos] = func(node[pos], v);
                pos += pos & -pos;
            }
        }

        T sum(int pos){
            // 1-indexed
            T res = init_v;
            while(pos > 0){
                res = func(res, node[pos]);
                pos = pos & (pos-1);
            }
            return res;
        }
};

void Main(){
    ll N,K; cin >> N >> K;
    VL a(N); REP(i,N) cin >> a[i];
    VL S(N+1,0); REP(i,N) S[i+1] = S[i] + a[i];

    VL b(N+1); REP(i,N+1) b[i] = S[i]-K*i; remove_duplication(b);
    map<ll,ll> m;
    REP(i,b.size()) m[b[i]] = i;

    ll ans = 0;
    BIT<ll> bit(N+1,[](ll a,ll b){return a+b;},0);
    bit.add(m[0]+1,1);
    REP(i,N){
        ll c = S[i+1] - K*(i+1);
        ans += bit.sum(m[c]+1);
        bit.add(m[c]+1,1);
    }
    cout << ans << en;
    return;
}

int main(void){
    cin.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t){
        Main();
    }
    return 0;
}
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << " = " << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define SP << " " <<

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vec;
typedef vector<P> pvec;
typedef vector<vector<int>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<int> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<int,vector<int>,greater<int>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;

const vector<int> DX = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> DY = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30); // 1073741824
const ll INF = (1LL << 60); // 1152921504606846976
const double PI = (3.141592653589794);
const double EPS = (0.0000000001); // 10^(-10)

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> inline T ceil(T a, T b) {return T((a + b - 1) / b);}
template<class T> inline T round(T a, T b) {return T(a / b);}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }
template <class T> inline void out(T &a) { bool flag=true; for(auto&x:a){if(flag) {flag=false;} else{ cout << ' '; } cout<<x; } cout << endl; }



//----------------------------------------------------------------
int nmax=200000; // 2*(10^5)
vvec G(nmax);


struct BIT{
private:
  vector<int> bit;
  int num;

public:
  BIT(vector<int> v){
    num = v.size();
    bit.resize(num);
    REP(i,num) bit[i] = v[i];
  }

  int sum(int i){
    int s = 0;
    while(i > 0){
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, int x){
    while(i <= num){
      bit[i] += x;
      i += i & -i;
    }
  }
};


void solve4ts()
{
    
    int n,k;
    cin>>n>>k;

    vector<int> a(n+1);
    rep(i,n) cin >> a[i+1];
    rep(i,n) a[i+1]+=a[i];
    rep(i,n+1){
        a[i]-=k*i;
    }
    map<int,int> mp;
    rep(i,n+1){
        mp[a[i]]++;
    }

    int idx=0;
    for(auto& x : mp){
        x.sc=idx;
        idx++;
    }

    vec node(n+10);
    BIT bit(node);
    int ans=0;

    for(int i=0;i<=n;i++){
        int find=mp[a[i]];
        find++;
        ans+=bit.sum(find);
        bit.add(find,1);
    }
    cout<<ans<<endl;
}
//-----------------------------------------------------------------

signed main(){ ios::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(15);
    int repeat = 1;
    // cin >> repeat;
    while(repeat--) solve4ts();
}
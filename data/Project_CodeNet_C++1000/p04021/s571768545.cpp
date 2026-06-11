#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<double> vdbl;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<int> > vvint;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;
typedef priority_queue<int, vector<int>, greater<int> > spqint; //小さい順に取り出し
typedef priority_queue<ll, vector<ll>, greater<ll> > spqll;     //小さい順に取り出し
typedef priority_queue<int, vector<int>, less<int> > bpqint;    //大きい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll> > bpqll;        //大きい順に取り出し

#define REP(i, n) for (int(i) = 0; (i) < (int)(n); i++)
#define FOR(i, a, b) for (int(i) = a; (i) < (int)b; i++)
#define IREP(i, v) for (auto i = v.begin(); i != v.end(); i++)
#define MOD 1000000007
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define TS to_string
#define BS binary_search
#define LB lower_bound
#define UB upper_bound
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)

const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = M_PI;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; } //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }     //最小公倍数

void yes()
{
    cout << "Yes" << endl;
}
void no()
{
    cout << "No" << endl;
}
//-----------------------------------------
int N ;
struct BIT {
  private:
   vector<int> bit;
 
  public:
   BIT(int size) {
     N = size;
     bit.resize(N + 1);
   }
 
   // 一点更新です
   void add(int a, int w) {
     for (int x = a; x <= N; x += x & -x) bit[x] += w;
   }
 
   // 1~Nまでの和を求める。
   int sum(int a) {
     int ret = 0;
     for (int x = a; x > 0; x -= x & -x) ret += bit[x];
     return ret;
   }
};

//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N ;
    int n = N ;
    vint a, b ;
    REP(i,n){
        int c ;
        cin >> c ;
        if(i%2==0){
            a.PB(c) ;
        }
        else{
            b.PB(c) ;
        }
    }
    sort(ALL(a)) ;
    reverse(ALL(a)) ;
    sort(ALL(b)) ;
    reverse(ALL(b)) ;
    vint d ;
    REP(i,n){
        if(i%2==0){
            d.PB(a[SZ(a)-1]) ;
            a.pop_back() ;
        }
        else{
            d.PB(b[SZ(b)-1]) ;
            b.pop_back() ;
        }
    }
    vint f ;
    f = d ;
    sort(ALL(f)) ;
    vint h(n) ;
    REP(i,n){
        auto itr = LB(ALL(f),d[i]) ;
        int g = distance(f.begin(),itr) ;
        h[i] = g ;
    }

    ll ans = 0 ;
    REP(i,n){
        if(i%2!=h[i]%2){
            ans++ ;
        }
    }

    cout << ans/2 <<endl;



    

    return 0;
}


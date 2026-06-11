#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
 
 
using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-10;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)


//ここから編集

 
ll modPow(ll x, ll n, ll mod = MOD){
    ll res = 1;
    while(n){
        if(n&1) res = (res * x)%mod;
 
        res %= mod;
        x = x * x %mod;
        n >>= 1;
    }
    return res;
}

int arr[110][110];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int W, H, N;
  cin >> W >> H >> N;

  vector<int> x1,x2,y1,y2;
  REP(i,N){
    int x, y, a;
    cin >> x >> y >> a;

    if(a == 1) x1.push_back(x);
    if(a == 2) x2.push_back(x);
    if(a == 3) y1.push_back(y);
    if(a == 4) y2.push_back(y);
  }

  sort(all(x1));
  sort(all(x2));
  sort(all(y1));
  sort(all(y2));
  
  
  int ans = H*W;
  int lm = 0, rm = W, lm2=0,rm2=H;
  if(x1.size() != 0){
    lm = x1[x1.size()-1];
  }
  if(x2.size() != 0){
    rm = x2[0];
  }
  if(y1.size() != 0){
    lm2 = y1[y1.size()-1];
  }
  if(y2.size() != 0){
    rm2 = y2[0];
  }
  cout << max(0, rm2-lm2) * max(0, rm-lm) << endl;
  return 0;
}
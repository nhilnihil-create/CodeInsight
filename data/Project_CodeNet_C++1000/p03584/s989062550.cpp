#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,k;
  cin >> n >> k;

  ll keta = 0;
  ll tmp = k;
  while(tmp > 0){
    keta++;
    tmp /= 2;
  }

  VLL a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];

  ll ans = 0;

  ll nomal = 0;
  rep(i,n){
    ll tmp = a[i];
    rep(j,30) {
      if( (k >> j) & 1 ) tmp |=  1LL << j;
    }
    if(tmp == k) {
      nomal += b[i];
    }
  }

  ans = max(nomal,ans);


  for(int bit = 30; bit >= 0; bit--){
    if( !((k >> bit) & 1) ) continue;
    // このビットより上のbitは一致している
    // それよりしたのビットはなんでも良い
    ll res = 0;
    ll highBit = ( (k >> bit) - 1) * (1LL << bit);
    // std::cout << std::bitset<5>(highBit) << endl;

    rep(i,n){
      // 上位bitがhighBitと一致
      ll tmpHigh = ( (a[i] >> bit)) * (1LL << bit);
      bool ngFlag = false;
      for(int j = 30; j >= 0; j--){
        if(  ((highBit >> j) & 1) == 0 && ((tmpHigh >> j) & 1) == 1){
          ngFlag = true;
        }
      }

      if(ngFlag == false){
        res += b[i];
      }
    }
    ans = max(res, ans);
  }
  cout << ans << endl;
  return 0;
}

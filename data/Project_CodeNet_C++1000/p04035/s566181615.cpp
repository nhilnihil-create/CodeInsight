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
  ll n,l;
  cin >> n >> l;
  VLL a(n);
  rep(i,n) cin >> a[i];
  rep(i,n-1){
    if(a[i]+a[i+1] >= l){
      cout << "Possible" << endl;
      rep(j,i){
        cout << j+1 << endl;
      }
      for(ll j = n-2; j >= i+1; j--){
        cout << j+1 << endl;
      }
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << "Impossible" << endl;
  return 0;
}

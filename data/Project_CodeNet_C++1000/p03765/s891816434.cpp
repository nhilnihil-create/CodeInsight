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
  string s,t;
  cin >> s >> t;
  int q;
  int n = s.size();
  int m = t.size();

  VLL ss(n,0);
  VLL tt(m,0);

  rep(i,n){
    if(s[i] == 'A') ss[i] = 1;
    if(s[i] == 'B') ss[i] = 2;
  }

  rep(i,m){
    if(t[i] == 'A') tt[i] = 1;
    if(t[i] == 'B') tt[i] = 2;
  }

  rep(i,n-1){
    ss[i+1] += ss[i];
  }
  rep(i,m-1){
    tt[i+1] += tt[i];
  }
  cin >> q;

  rep(i,q){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--,b--,c--,d--;

    ll ansS = ss[b];
    ll ansT = tt[d];
    if(a > 0) ansS -= ss[a-1];
    if(c > 0) ansT -= tt[c-1];

    if( (ansS % 3) == (ansT % 3) ) {
      cout << "YES" << "\n";
    }else{
      cout << "NO" << "\n";
    }
  }
  return 0;
}

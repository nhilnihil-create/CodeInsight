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
ll n, a, b;
bool enough(ll t, vector<ll> & h){
  ll plus = a-b;
  ll cnt = 0;
  rep(i,n){

    if( (h[i] - t * b)> 0){
      cnt += max(0LL, (h[i] - (t*b) + (plus-1) ) / plus);
    }
  }
  //cout << t << ':' << cnt << endl;
  if(cnt <= t) return true;
  else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    VLL h(n);

    rep(i,n) cin >> h[i];
    sort(all(h),greater<ll>());

    ll left = 0;
    ll right = 1e9;
    while(right - left > 1){
      ll mid = (left + right) / 2;
      if(enough(mid, h)) right = mid;
      else left = mid;
      //cout << left << ',' << right << endl;
    }
    cout << right << endl;
    return 0;
}

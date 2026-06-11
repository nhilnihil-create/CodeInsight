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

VI win[101010];

int solve(int x){
  vector<int> v;
  rep(i,win[x].size()){
    v.push_back(solve(win[x][i]));
  }

  sort( all(v) , greater<int>() );

  ll res = 0;
  rep(i,v.size()){
    res = max(res, i + v[i] + 1);
  }
  return res;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;

  int a;
  rep(i,n-1){
    cin >> a, a--;
    win[a].push_back(i+1);;
  }
  
  cout << solve(0) << endl;
  return 0;
}

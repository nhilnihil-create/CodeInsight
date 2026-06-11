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
  ll K;
  const ll N = 50;
  cin >> K;
  cout << N << endl;
  ll add_Cnt = K/N;
  ll amari_Cnt = K%N;
  VLL ans(N,0);

  rep(i,N){
    ans[i] += N - 1 + add_Cnt;
    if(i < N - amari_Cnt){
      ans[i] -= amari_Cnt;
    } else {
      ans[i] += N - amari_Cnt + 1;
    }
  }

  rep(i,N){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

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


//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

const int mod = 1e9 + 7;
int main(){
  int n;
  cin  >> n;

  VLL T(n),A(n);

  rep(i,n) cin >> T[i];
  rep(i,n) cin >> A[i];

  vector<bool> T_equal(n,false), A_equal(n,false);
  T_equal[0]    = true;
  A_equal[n-1]  = true;
  rep(i,n-1)                     if(T[i] != T[i+1]) T_equal[i+1] = true;
  for(int i = n-1; i >= 1; i--)  if(A[i] != A[i-1]) A_equal[i-1] = true;

  // rep(i,n) cout << T_equal[i] << " ";
  // cout << endl;
  // rep(i,n) cout << A_equal[i] << " ";
  // cout << endl;
  ll ans = 1;
  rep(i,n){
    if(T_equal[i] || A_equal[i] ){
      if(T_equal[i] && A_equal[i] && T[i] != A[i]){
        cout << 0 << endl;
        return 0;
      }else if(T_equal[i] && T[i] > A[i]){
        cout << 0 << endl;
        return 0;
      }else if(A_equal[i] && T[i] < A[i]){
        cout << 0 << endl;
        return 0;
      }
      continue;
    }
    ans = ( ans * min(T[i],A[i]) ) % mod;
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1000000000;

//long long
using ll = long long;

//出力系
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

// 最小公倍数
unsigned lcm(unsigned a, unsigned b){
    return a / gcd(a, b) * b; 
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
  ll n;
  cin >> n;
  vector<ll>t(n);
  REP(i, n) cin >> t[i];
  vector<ll>a(n);
  REP(i, n) cin >> a[i];

  // vector<ll>check(n, -1);
  bool flag = true;

  vector<ll>nt(n);
  ll t_now = -1;
  REP(i, n){
    if(t_now < t[i]) nt[i] = 1, t_now = t[i];
    else nt[i] = t_now;
    // cout << t_now << endl;
  }
  vector<ll>na(n);
  ll a_now = -1;
  for(ll i = n - 1; i >= 0; i--){
    if(a_now < a[i]) na[i] = 1, a_now = a[i];
    else na[i] = a_now;
    // cout << a_now << endl;
  }

  REP(i, n){
    if(nt[i] == 1 && na[i] == 1) if(t[i] != a[i]) flag = false;
    if(nt[i] == 1) if(t[i] > a[i]) flag = false;
    if(na[i] == 1) if(a[i] > t[i]) flag = false;
  }
  //  for(auto x : nt) cout << x << "\n";

  ll ans = 1;
  if(flag){
    REP(i, n){
      ans *= min(na[i], nt[i]);
      ans %= MOD;
    }
  }

  flag ? cout << ans << "\n" : cout << 0 << "\n";
  return 0;

}

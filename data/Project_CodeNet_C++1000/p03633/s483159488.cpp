#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}
const ll MOD = 1e9+7;
long long Comb(int n, int i){long long ans = 1; if(i>n || i < 0) return 0; if(i == 0 || i == n) return 1; else {for(int j = 1; j <= i; ++j){
      ans *=(n+1-j);
      ans /= j;
      ans %= MOD;} }return ans;}

long long gcd(ll a, ll b){
  if(b == 0) return a;
  else return gcd(b, a%b);
}

template<typename T> void change(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

long long lcm(ll a, ll b){
  if(b > a) change(a, b);
  ll g = gcd(a, b);
  return a / g * b;
}

void solve(){
  int n; cin >> n;
  ll ans = 1;
  for(int i = 0; i < n; ++i){
    ll tmp; cin >> tmp;
    ans = lcm(ans, tmp);
    // cout << ans << endl;
  }
  cout << ans << endl;
}

int main(){
  solve();
  return 0; 
}

#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  ll n, a, b;  cin >> n >> a >> b;
  vector<ll> x(n); cin >> x;
  ll ans = 0;
  for (int i = 1; i <= n-1; ++i){
    ans += min((x[i]-x[i-1])*a, 1LL*b);
  }
  cout << ans << "\n";
  return 0;
}	
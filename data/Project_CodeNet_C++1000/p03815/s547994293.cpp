#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  ll x; cin >> x;
  ll ans = x/11*2;
  x -= ans/2*11;
  ans += (x+5)/6;
  cout << ans << "\n";
  return 0;
}
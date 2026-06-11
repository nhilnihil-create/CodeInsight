#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  ll a, b, x; cin >> a >> b >> x;
  if(a==0) {
    cout << b/x+1 << "\n";
  } else {
    cout << b/x - (a-1)/x << "\n";
  }
  return 0;
}
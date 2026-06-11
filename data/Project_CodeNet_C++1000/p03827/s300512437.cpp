#include <bits/stdc++.h>
using namespace std;

#define ll long long

template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

void solve() {
  int x=0, max=0;
  int n;
  string s;
  cin >> n >> s;
  for(int i=0; i<n; ++i) {
    if(s[i] == 'I') {
      ++x;
    } else {
      --x;
    }
    if(max<x) max=x;
  }
  cout << max << endl;

  return;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  while(T--) solve();

  return 0;
}

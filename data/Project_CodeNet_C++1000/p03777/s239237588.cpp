#include <bits/stdc++.h>
using namespace std;

#define ll long long

template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

void solve() {
  char a,b; cin >> a >> b;

  if(a=='H') {
    if(b=='H') {
      cout << 'H' << endl;
    } else {
      cout << 'D' << endl;
    }
  } else {
    if(b=='H') {
      cout << 'D' << endl;
    } else {
      cout << 'H' << endl;
    }
  }

  return;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}

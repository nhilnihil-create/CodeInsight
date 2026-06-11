#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> a(h);

  rep(i,h) cin >> a[i];
  

  rep(i,h+1) {
    if (i == 0) {
      rep(j,w+2) cout << '#';
      cout << endl;
    } else {
      cout << '#' << a[i-1] << '#' << endl;
    }
  }


  rep(i,w+2) cout << '#';
  cout << endl;

  return 0;
}
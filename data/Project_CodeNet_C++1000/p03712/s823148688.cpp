#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  
  rep(i,W+2) cout << '#';
  cout << endl;
  
  rep(i,H) {
    cout << '#';
    cin >> a[i];
    cout << a[i];
    cout << '#' << endl;
  }
  
  rep(i,W+2) cout << '#';
  cout << endl;
  
}

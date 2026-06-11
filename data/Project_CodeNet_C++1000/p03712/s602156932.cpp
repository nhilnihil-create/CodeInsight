#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int H, W;
  cin >> H >> W;
  rep(i, W + 2) {
    cout << "#";
  }
  cout << " " << endl;
  string S;
  rep(i, H) {
    cout << "#";
    cin >> S;
    cout << S;
    cout << "#" << endl;
  }
  rep(i, W + 2) {
    cout << "#";
  }
}
    

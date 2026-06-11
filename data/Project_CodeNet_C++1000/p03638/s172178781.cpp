#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,H,W,n;
  cin >> H >> W;
  vector<int> a;
  for (cin >> N; N; N--) {
    cin >> n;
    a.push_back(n);
  }
  int b[H][W];
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H && !(j%2); i++, a[a.size()-1]--) {
      if (a.back()) {
      	b[i][j] = a.size();
      } else {
        a.pop_back();
        b[i][j] = a.size();
      }
    }
    for (int i = H-1; i+1 && j%2; i--, a[a.size()-1]--) {
      if (a.back()) {
        b[i][j] = a.size();
      } else {
        a.pop_back();
        b[i][j] = a.size();
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << b[i][j] << ' ';
    }
    cout << '\n';
  }
}
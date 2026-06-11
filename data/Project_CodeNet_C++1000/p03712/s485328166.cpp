#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<char> p(H * W);
  for(int i = 0; i < H * W; i++) {
    cin >> p.at(i);
  }
  for(int i = 0; i < W + 2; i++) {
    cout << '#';
  }
  cout << endl;
  for(int i = 0; i < H * W; i++) {
    if(i % W == 0) {
      cout << '#';
    }
    cout << p.at(i);
    if(i % W == W - 1) {
      cout << '#' << endl;
    }
  }
  for(int i = 0; i < W + 2; i++) {
    cout << '#';
  }
  cout << endl;
}
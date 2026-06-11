#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> pixels(H);
  for (int i = 0; i < H; i++) {
    cin >> pixels.at(i);
  }
  for (int i = 0; i < W + 2; i++) {
    cout << '#';
  }
  cout << endl;
  for (int i = 0; i < H; i++) {
    cout << '#' << pixels.at(i) << '#' << endl;
  }
  for (int i = 0; i < W + 2; i++) {
    cout << '#';
  }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> str(H);
  for (int i = 0; i < H; i++) {
    string s;
    cin >> s;
    str.at(i) = "#" + s + "#";
  }
  for (int i = 0; i < W + 2; i++) {
    cout << '#';
  }
  cout << endl;
  for (int i = 0; i < H; i++) {
    cout << str.at(i) << endl;
  }
  for (int i = 0; i < W + 2; i++) {
    cout << '#';
  }
  cout << endl;
}
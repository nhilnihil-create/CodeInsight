#include <bits/stdc++.h>
using namespace std;

int main() {
  int  H, W;
  cin >> H >> W;
  string box;
  for (int j = 0; j < W + 2; j++) {
    box += '#';
  }
  vector<string> total(H + 2);
  total.at(0) = box;
  for (int i = 0; i < H; i++) {
    string a;
    cin >> a;
    string newa = '#' + a + '#';
    total.at(i + 1) = newa;
  }
  total.at(H + 1) = box;
  for (int k = 0; k < total.size(); k++) {
    cout << total.at(k) << endl;
  }
}


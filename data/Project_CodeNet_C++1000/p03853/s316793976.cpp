#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> ans(H);
  for(int i = 0; i < H; i++) {
    cin >> ans[i];
  }
  for(string s:ans) {
    cout << s << endl;
    cout << s << endl;
  }
}
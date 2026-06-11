#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < W + 2; i++) {
    cout << "#";
  }
  cout << endl;
  for (int i = 0; i < H; i++) {
    cout << "#";
    for (int j = 0; j < W; j++) {
      vector<char> vec(W);
      cin >> vec.at(j);
      cout << vec.at(j);
    }
    cout << "#" << endl;
  }
  for (int i = 0; i < W + 2; i++) {
    cout << "#";
  }
  cout << endl;
}
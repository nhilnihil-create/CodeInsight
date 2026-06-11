#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
   for (int i = 0; i < H; i++) {
     vector<char> vec(W);
      for (int j = 0; j < W; j++) {
     cin >> vec.at(j);
      }
      for (int k = 0; k < W; k++) {
        cout << vec.at(k);
      }
     cout << endl;
      for (int k = 0; k < W; k++) {
        cout << vec.at(k);
      }
     cout << endl;
   }
}
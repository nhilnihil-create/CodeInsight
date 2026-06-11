#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<char>c(W);
  for (int i =0; i < H; i++){
    for (int l =0; l < W; l++){
      cin >> c.at(l);
    }
    for (int k =0; k < W; k++){
      cout << c.at(k);
    }
    cout << endl;
    for (int m =0; m < W; m++){
      cout << c.at(m);
    }
    cout << endl;
  }
}
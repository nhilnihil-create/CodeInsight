#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  string a, str;
  
  for(int i = 0; i < H; i++) {
    cin >> str;
    a += str;
  }
  
  for(int i = 0; i < W+2; i++) {
    cout << "#";
  }
  cout << endl;
  for(int i = 0; i < H; i++) {
    cout << "#";
    for(int j = 0; j < W; j++) {
      cout << a.at(j + i*W);
    }
    cout << "#" << endl;
  }
  for(int i = 0; i < W+2; i++) {
    cout << "#";
  }
  cout << endl;
}

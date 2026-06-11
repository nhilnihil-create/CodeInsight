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
    vector<char> a(W);
    
    for (int j = 0; j < W; j++) {
      cin >> a.at(j);
    }
    cout << "#" ;
    
    for (int j = 0; j < W; j++) {
      cout << a.at(j);
    }
    cout << "#" << endl;
  }
  
  for (int i = 0; i < W + 2; i++) {
    cout << "#";
  }
  cout << endl;

}

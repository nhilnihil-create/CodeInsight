#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<char> A(W, '#'), B(W + 1, '#');
  
  for (int i = 0; i < W; i++) cout << A.at(i);
  cout << "##" << endl;
  
  for (int i = 0; i < H; i++) {
    
    cout << '#';
    
    for (int j = 0; j < W; j++) {
      cin >> B.at(j);
      cout << B.at(j);
    }
    
    cout << '#' << endl;
  }
  
  for (int i = 0; i < W; i++) cout << A.at(i);
  cout << "##" << endl;
  
}
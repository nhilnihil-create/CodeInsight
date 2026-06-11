#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<char> v(W + 2, '#'), y(W);
  
  for(int i = 0; i < W + 1; i++){
   cout << v.at(i);
  }
  cout << '#' << endl;
  
  for(int i = 0; i < H; i++){
    cout << '#';
    for(int n = 0; n < W; n++){
      cin >> y.at(n);
      cout << y.at(n);
    }
    cout << '#' << endl;
  }
  for(int i = 0; i < W + 2; i++){
   cout << v.at(i);
  }
}
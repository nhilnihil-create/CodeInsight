#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<char> vec(H * W);
  int a = 0;
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> vec.at(a);
      a++;
    }
  }
  
  a = 0;
  
  for (int i = 0; i < W + 2; i++) {
    cout << '#';
  }
  
  cout << endl;
  
  for (int i = 0; i < H; i++) {
    cout << '#';
    for (int j = 0; j < W; j++) {
      cout << vec.at(a);
      a++;
    }
    cout << '#' << endl;
  } 
  
  for (int i = 0; i < W + 2; i++) {
    cout << '#';
  }
  
  cout << endl;
  
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  
  cout << '#';
  for(int i = 0; i < W; i++){
    cout << '#';
  }
  cout << '#' << endl;
  
  string pic;
  
  for(int i = 0; i < H; i++){
      cin >> pic;
      cout << '#' << pic << '#' << endl;
  }
 
  cout << '#';
  for(int i = 0; i < W; i++){
    cout << '#';
  }
  cout << '#' << endl;  
}
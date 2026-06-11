#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  vector<string> vec(H+2);
  for (int i=0; i < W + 2; i++){
  vec.at(0) = vec.at(0) + "#";
    vec.at(H + 1) = vec.at(H + 1) + "#";
  }
  
  for (int i=0; i < H; i++){
  cin >> vec.at( i+1 );
    vec.at( i+1 ) = "#" + vec.at(i+1) + "#";
  }
  
  for (int i=0; i < H + 2; i++){
  cout << vec.at(i) << endl;
  }
  
  
}
 
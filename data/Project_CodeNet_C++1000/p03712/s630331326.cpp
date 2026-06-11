#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  char tmp;
  for(int i = 0; i < W + 2; i++){
    cout << '#';
    if(i == W + 1) cout << endl;
  }
  for(int i = 0; i < H; i++){
    cout << '#';
    for(int j = 0; j < W; j++){
      cin >> tmp;
      cout << tmp;
      if(j == W - 1) cout << '#' << endl;
    }
  }   
  for(int i = 0; i < W + 2; i++){
    cout << '#';
    if(i == W + 1) cout << endl;
  }
  return 0;
}
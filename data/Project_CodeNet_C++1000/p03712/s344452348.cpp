#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W; cin >> H >> W;
  int a = 0;
  while(a < W + 2){ 
    cout << '#';
    a++;
  }
  cout << endl;
  for(int i = 0; i < H; i++){
    cout << '#';
    for(int j = 0; j < W; j++){
      char b; cin >>b;
      cout << b;
    }
    cout << '#' << endl;
  }
  a = 0;
  while(a < W + 2){
    cout << '#';
    a++;
  }
  cout <<endl;
      
}
  
  
  
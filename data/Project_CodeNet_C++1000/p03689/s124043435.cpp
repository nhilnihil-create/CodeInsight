
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int CON = 1e9-1;

signed main(void){
  int H,W,h,w; cin >> H >> W >> h >> w; 
  if( H % h == 0 && W % w == 0 ){ cout << "No" << endl; return 0;}
  
  cout << "Yes" << endl;
  //左上の値は、ギリギリまで大きくしたい
  
  int a = CON/(h*w-1);
 
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      
      if( i % h == h-1 && j % w == w-1 ){ cout << -((h*w-1)*a+1) << " ";}
      else{ cout << a << " ";}
      
    }
    
    cout << endl;
  }
  
  return 0;
}
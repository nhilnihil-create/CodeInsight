#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;
  set<int> w,s;
  //入れられる水の重量を列挙する。
  for(int i = 0;i <= 30; i++){
    for(int j = 0; j <= 30;j++){
      int t = 100 * A * i + 100 * B * j;
      if(t <= F && t > 0) w.insert(t);
    }
  }
  //入れられる砂糖の重量を列挙する。
  for(int i = 0; i <= 3000; i++){
    for(int j = 0; j <= 3000;j++){
      int t = C * i + D * j;
      if(t <= F) s.insert(t);
    }
  }
  double max_M = 0;
  int ans_s_w = 0;
  int ans_s = 0;
  for(auto x: w){
    for(auto y: s){
      //重量がF以下であること
      if(x + y > F ) continue;
      //砂糖が溶け切っていること。
      if( y >  x / 100 * E) continue;
      double t = (double)100 * y / ( x + y );
      if(max_M <= t ){
        max_M = t;
        ans_s_w = x + y;
        ans_s = y;
      }
    }
  }
  cout << ans_s_w << " " <<  ans_s;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;
  
  int w,s;
  int ans_ws = 0;
  int ans_s = 0;
  
  for(int a=0;100*A*a<=F;a++){
    for(int b=0;100*A*a+100*B*b<=F;b++){
      for(int c=0;100*A*a+100*B*b+C*c<=F;c++){
        for(int d=0;100*A*a+100*B*b+C*c+D*d<=F;d++){
          w = 100*A*a + 100*B*b;
          s = C*c + D*d;
          if(E*w >= s*100 && s*ans_ws >= (w+s)*ans_s){
            ans_ws = w + s;
            ans_s = s; 
          }
        }
      }
    }
  }
  
  cout << ans_ws << " " << ans_s << "\n"; 
}

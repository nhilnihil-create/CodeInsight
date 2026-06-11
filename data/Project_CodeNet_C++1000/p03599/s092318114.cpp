#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D,E,F,W,S;
  cin >> A >> B >> C >> D >> E >> F;
  double temp,max;
  max = 0.0;
  W = 0;
  S = 0;
  for(int a=0;100*A*a<=F;a++){
    for(int b=0;100*B*b<=F-100*A*a;b++){
      for(int c=0;c*C<=F-100*A*a-100*B*b;c++){
        for(int d=0;d*D<=F-100*A*a-100*B*b-c*C;d++){
          temp = 100.0*(double)(C*c+D*d)/(double)(100*A*a+100*B*b+c*C+d*D);
          if(C*c+D*d<=(A*a+B*b)*E){
          if(temp >= max){
            max = temp;
            W = 100*(A*a+B*b)+c*C+d*D;
            S = C*c + D*d;
          }
          }   
        }
      }
    }
  }
  cout << W << " " <<S << endl;
}
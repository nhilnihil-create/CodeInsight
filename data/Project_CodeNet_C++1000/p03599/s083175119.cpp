#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;
  double r=-100.0;
  double r1,r2,x,y,z;
  for(int i=0; i<31;i++){
    x=100*A*i;
    for(int j=0;j<31;j++){
      x=100*A*i+100*B*j;
      for(int k=0;k<51;k++){
        y= k*C;
        z=100*A*i+100*B*j+ k*C;
        for(int  l=0;l<51;l++){
          y=k*C+l*D;
          z=100*A*i+100*B*j+k*C+l*D;
          if(z>0 && z<=F && y<=(E*x)/100 && r<(100*y)/z){
            r=(100*y)/z;
            r1=z;
            r2=y;
          }
        }
      }
    }
  }
  cout << r1 << " "<< r2<< endl;
}
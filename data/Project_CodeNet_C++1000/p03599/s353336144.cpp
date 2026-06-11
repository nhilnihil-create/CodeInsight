#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;
  double N,max_N=0;
  int max_X=0,max_Y=0;
  for(int i=0;i<101;i++){
    for(int j=0;j<101;j++){
      for(int k=0;k<101;k++){
        for(int l=0;l<101;l++){
          int X=100*A*i+100*B*j;
          int Y=C*k+D*l;
          if(X+Y<=F && X*E/100>=Y){
            N=(double)Y/(X+Y);
            if(N>=max_N){
              max_N=N;
              max_X=X;
              max_Y=Y;
            }
          }
        }
      }
    }
  }
  cout << max_X+max_Y << " " << max_Y << endl;
}
              

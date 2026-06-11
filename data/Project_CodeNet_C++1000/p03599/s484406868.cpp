#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d,e,f,wtr,sgr;
  cin >> a >> b >> c >> d >> e >> f;
  double cal=0.0;
  int ans_sgwtr=100*a;
  int ans_sgr=0;
  for(int A=0;A<31;++A){
    for(int B=0;B<31;++B){
      for(int C=0;C<101;++C){
        for(int D=0;D<101;++D){
        	wtr = 100*a*A+100*b*B;
        	sgr = C*c+D*d;
          if(wtr==0)break;
          if(wtr+sgr<=f && (wtr)/100*e>=sgr){
            double nongdu=(double)(100*(sgr))/(double)(wtr+sgr);
            if(cal<nongdu){
              ans_sgwtr = wtr+sgr;
              ans_sgr = sgr;
              cal = nongdu;
            }
          }
        }
      }
    }
  }
 
  cout << ans_sgwtr << " " << ans_sgr << endl;
  return 0;
 
}
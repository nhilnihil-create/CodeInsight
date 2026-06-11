#include<bits/stdc++.h>
using namespace std;



int main(){
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  double cal=0.0;
  int ans_mizu=100*a;
  int ans_situ=0;
  for(int A=0;A<31;++A){
    for(int B=0;B<31;++B){
      for(int C=0;C<101;++C){
        for(int D=0;D<101;++D){
          if(100*a*A+100*b*B==0)break;
          if(100*a*A+100*b*B+C*c+D*d<=f && (100*a*A+100*b*B)/100*e>=C*c+D*d){
            double noudo=(double)(100*(C*c+D*d))/(double)(100*a*A+100*b*B+C*c+D*d);
            if(cal<noudo){
              ans_mizu=100*a*A+100*b*B+C*c+D*d;
              ans_situ=C*c+D*d;
              cal=noudo;
            }
          }
        }
      }
    }
  }

  cout << ans_mizu << " " << ans_situ << endl;
  return 0;

}

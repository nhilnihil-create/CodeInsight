#include <bits/stdc++.h>
using namespace std;

int main(){
  double A,B,C,D,E,F,maxN,yoshitsu,yobai;
  cin >>A>>B>>C>>D>>E>>F;
  maxN=0;
  yoshitsu=0;
  yobai=0;
  for(int m1=0;m1<(F/(A*100)+1);m1++){
    for(int m2=0;m2<(F/(B*100)+1);m2++){
      for(int m3=0;m3<(F/C+1);m3++){
        for(int m4=0;m4<(F/D+1);m4++){
          //cout<<m1<<m2<<m3<<m4<<endl;
          if(m1*A*100+m2*B*100+m3*C+m4*D==0) continue;
          if(m1*A*100+m2*B*100+m3*C+m4*D>F) continue;
          if((C*m3+D*m4)/(m1*A*100+m2*B*100+m3*C+m4*D)>E/(100+E)) continue;
          if((C*m3+D*m4)/(m1*A*100+m2*B*100+m3*C+m4*D)>maxN){
            maxN=(C*m3+D*m4)/(m1*A*100+m2*B*100+m3*C+m4*D);
            yoshitsu=C*m3+D*m4;
            yobai=m1*A*100+m2*B*100+C*m3+D*m4;
            //cout<<maxN<<" "<<yoshitsu<<" "<<yobai<<endl;
          }
        }
      }
    }
  }
  cout<<max(yobai,100*A)<<" "<<yoshitsu<<endl;
  return 0;
}

          
    
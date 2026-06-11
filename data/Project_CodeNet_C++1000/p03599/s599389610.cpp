#include <bits/stdc++.h>
using namespace std;


int main() {
 	int A,B,C,D,E,F;
  cin>>A>>B>>C>>D>>E>>F;
  int X=0,Y=0;
  double ans=0.00;
  for(int a=0;100*A*a<=F;a++){
    for(int b=0;100*B*b<=F-100*A*a;b++){
      for(int c=0;C*c<=F-100*A*a-100*B*b;c++){
        for(int d=0;D*d<=F-100*A*a-100*B*b-C*c;d++){
          int x=100*A*a+100*B*b;
          int y=C*c+D*d;
          if(x+y==0|| 100*y>x*E) continue;
          else if((double)100*y/(x+y)>=ans){//水は０ではない
            X=x; Y=y;
            ans=(double)100*y/(x+y);
          }
        }
      }
    }
  }
  cout<<X+Y<<" "<<Y<<endl;
}
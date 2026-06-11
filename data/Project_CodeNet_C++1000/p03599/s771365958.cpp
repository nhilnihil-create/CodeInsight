#include<bits/stdc++.h>
#include<math.h>
using namespace std;
 
int main(){
  int A,B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  double noudo = 0.0;
  int tot = 100*A, sugar = 0;
  for (int a=0;a<=F/(100*A);a++){
    for (int b=0;b<=(F-100*A*a)/(100*B);b++){
      if (a==0 && b==0) continue;

      for (int c=0;c<=(F-100*A*a-100*B*b)/C;c++){
        for (int d=0;d<=(F-100*A*a-100*B*b-C*c)/D;d++){
          if (1.0*(C*c+D*d)/(100*A*a+100*B*b+C*c+D*d) <= 1.0*E/(100+E) && 1.0*(C*c+D*d)/(100*A*a+100*B*b+C*c+D*d) > noudo){
            tot = 100*A*a+100*B*b+C*c+D*d;
            sugar = C*c+D*d;
            noudo = 1.0*sugar/tot;
          }
        }
      }
    }
  }
  cout << tot << " " << sugar << endl;

}
 
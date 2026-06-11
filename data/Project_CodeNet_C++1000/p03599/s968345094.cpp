#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D,E,F;
  cin>>A>>B>>C>>D>>E>>F;

  double m=0;
  vector<int> ans={100*A,0};

  for(int a=0;a<=30;++a){
    for(int b=0;b<=30;++b){
      int W=100*(a*A+b*B);
      if(W>=F) continue;
      for(int c=0;c<=100;++c){
        for(int d=0;d<=100;++d){
          int S=c*C+d*D;
          if(S==0 && W==0) continue;
          else if(S+W>F) continue;
          else if((W/100)*E<S) continue;
          else{
            if(m<(double)(100*S)/(S+W)){
              ans[0]=S+W;
              ans[1]=S;
              m=(double)(100*S)/(S+W);
            }
          }
        }
      }
    }
  }

  cout<<ans[0]<<" "<<ans[1]<<endl;
}

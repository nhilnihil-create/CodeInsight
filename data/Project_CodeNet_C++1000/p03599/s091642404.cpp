#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  set<int>water,sugar;
  for(int i=0;i<31;i++){
    for(int j=0;j<31;j++){
      if(100*a*i+100*b*j<=f){
        water.insert(100*a*i+100*b*j);
      }
    }
  }
  for(int i=0;i<30*e+1;i++){
    for(int j=0;j<30*e+1;j++){
      if(c*i+d*j<=30*e)sugar.insert(c*i+d*j);
    }
  }
  int ans1=100*a,ans2=0;
  for(auto x:water){
    for(auto y:sugar){
      if(x+y<=f&&x*e/100>=y){
        if(x*((ans1-ans2)/100*e-ans2)>(ans1-ans2)*(x/100*e-y)){
          ans1=x+y;
          ans2=y;
        }
      }
    }
  }
  cout<<ans1<<' '<<ans2<<endl;
}
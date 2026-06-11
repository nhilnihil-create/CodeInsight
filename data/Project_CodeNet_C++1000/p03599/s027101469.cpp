#include<bits/stdc++.h>
using namespace std;
int main(){
  const double EPS=1e-8;
  int i,j,k,a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  double ans=0;
  int a1=100*a,a2=0;
  vector<int> x(3010,0);
  for(i=0;i<=f;i+=c){
    for(j=0;j<=f;j+=d){
      if(i+j<=f){
        x[i+j]=1;
      }
    }
  }
  vector<int> y;
  for(i=0;i<=f;i++){
    if(x[i]==1){
      y.push_back(i);
    }
  }
  for(i=0;i<=f/(100*a);i++){
    for(j=0;j<=f/(100*b);j++){
      for(k=0;k<y.size();k++){
        if(100*a*i+100*b*j+y[k]>f){
          continue;
        }
        if(e*(100*a*i+100*b*j)<100*y[k]){
          continue;
        }
        if(ans<100*(double)y[k]/(double)(y[k]+100*a*i+100*b*j)-EPS){
          ans=100*(double)y[k]/(double)(y[k]+100*a*i+100*b*j);
          a1=100*a*i+100*b*j+y[k],a2=y[k];
        }
      }
    }
  }
  cout << a1 << ' ' << a2 << endl;
}
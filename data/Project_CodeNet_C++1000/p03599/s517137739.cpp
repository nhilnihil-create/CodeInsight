#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  cout<<setprecision(5)<<fixed;
  int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  vector<int> w,s;
  for(int i=0; i*100*a<=f; i++){
    for(int j=0; i*100*a+j*100*b<=f; j++){
      w.push_back(i*100*a+j*100*b);
    }
  }
  for(int i=0; i*c<=f; i++){
    for(int j=0; i*c+j*d<=f; j++){
      s.push_back(i*c+j*d);
    }
  }
  double p=0;
  int q,r;
  for(auto x : w){
    for(auto y : s){
      if(x==0) continue;
      if((100+e)*y<=e*(x+y) && x+y<=f){
        if(p<=(double)(100*y)/(double)(x+y)){
          p=(double)(100*y)/(double)(x+y); q=x+y; r=y; 
        }
      }
    }
  }
  cout<<q<<" "<<r<<endl;
}
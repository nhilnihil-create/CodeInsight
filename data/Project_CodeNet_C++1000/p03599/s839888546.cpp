#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using ll = long long;

int main(){
  int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  a*=100,b*=100;
  int s = 0;
  int w = 0;
  double r = 0;
  int answ,anss;
  for(int i = 0; a*i <= f; i++){
    for(int j = 0; a*i + b*j <=f; j++){
      if(i==0&&j==0)continue;
      w = a*i + b*j;
      for(int k = 0; c*k + w <=f; k++){
        for(int l = 0; c*k + d*l + w <=f; l++){
          s = c*k + d*l;
          if(s<=e*w/100 && r<s*100.0/(s+w)){
            anss = s;
            answ = w;
            r = s*100.0/(s+w);
            //cout<<"r="<<r<<endl;
            //cout<<anss+answ<<" "<<answ<<endl;
          }
        }
      }
    }
  }
  if(anss==0)answ=a;
  cout<<answ+anss<<" "<<anss<<endl;
  return 0;
}






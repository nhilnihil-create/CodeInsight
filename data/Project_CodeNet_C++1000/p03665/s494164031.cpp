#include <bits/stdc++.h>
using namespace std;

long p[55][55];

void p_init(){
  p[0][0]=1;
  p[1][0]=1,p[1][1]=1;
  for(int n=2;n<=50;n++){
    for(int r=0;r<=n;r++){
      if(r==0||r==n) p[n][r]=1;
      else{
        p[n][r]=p[n-1][r-1]+p[n-1][r];
      }
    }
  }
}

long com(long n,long r){
  return p[n][r];
}

int main() {
  long N,P;
  cin>>N>>P;
  long ans=0;
  long o=0,e=0;
  for(int i=0;i<N;i++){
    long a;
    cin>>a;
    if(a%2==0) e++;
    else o++;
  }
  p_init();
  if(P==0){
    for(int i=0;i<=o;i+=2){
      ans+=long(pow(2,e))*com(o,i);
    }
  }
  else{
    for(int i=1;i<=o;i+=2){
      ans+=long(pow(2,e))*com(o,i);
    }
  }
cout<<ans<<endl;
}

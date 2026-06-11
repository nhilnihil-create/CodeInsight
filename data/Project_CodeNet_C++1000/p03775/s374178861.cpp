#include<bits/stdc++.h>
using namespace std;
int ans=11;

long long keta(long long num){
  int tmp=0;
  while(num){
    tmp++;
    num/=10;
  }
  ans=min(ans,tmp);
  return 0;
}

int main(){
  long long n;
  cin>>n;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      if(i>=n/i){
        keta(i);
      }
      else
        keta(n/i);
    }
  }
  cout <<ans<<endl;
}
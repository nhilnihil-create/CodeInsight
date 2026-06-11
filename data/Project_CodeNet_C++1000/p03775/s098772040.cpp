#include<iostream>
#include<algorithm>
using namespace std;

int count(long long  n){
  int tmp=0;
  while(n>0){
    tmp++;
    n/=10;
  }
  return tmp;
}

int main(){
  long long n;
  cin>>n;
  int ans=2e9,tmp;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      long long b;
      b=n/i;
      tmp=max(count(i),count(b));
      ans=min(ans,tmp);
    }
  }
  cout<<ans<<endl;
  return 0;
}
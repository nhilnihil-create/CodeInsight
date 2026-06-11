#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;
const long long Mo=1000000007;
         

long long gcn(long long x,long long y){
  if(x%y==0){  
    return y;    
  }
  else{
    return gcn(y,x%y);
  }
}

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(void){
  long long tmp,tmp1,tmp2;
  long long n,k,s;
  long long ttl=0;
  long long ac[100000]={};
  long long x=0;
  long long i,j;
  long long res=0;

  cin>>k>>s;

  for(i=0;i<=min(k,s);i++){
    tmp=s-i;
    if(tmp>2*k){
    }
    else if(tmp>=k){
      res+=(2*k-tmp+1);
    }
    else if(tmp<k){
      res+=(tmp+1);
    }
  }
  
  //cout<<setprecision(15)<<res<<endl;
  cout<<res<<endl;

  
  return 0;
    }
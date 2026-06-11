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
  long long tmp1,tmp2;
  long long n,m;
  long long x=0;
  long long i,j;
  long double res=0.0;

  cin>>n>>m;
  long long n_b[n];
  int b[n]={};
  b[0]=1;
  for(i=0;i<n;i++){
    n_b[i]=1;
  }
  
  for(i=0;i<m;i++){
    cin>>tmp1>>tmp2;
    tmp1--;
    tmp2--;
    if(b[tmp1]==1){
      if(n_b[tmp1]==1){
        b[tmp1]=0;
        b[tmp2]=1;
      }
      else{
        b[tmp2]=1;
      }
    }
    n_b[tmp1]--;
    n_b[tmp2]++;
  }
  
  for(i=0;i<n;i++){
    res+=b[i];
  }
  
  //cout<<setprecision(15)<<res<<endl;
  cout<<res<<endl;

  
  return 0;
    }
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
  long long tmp;
  long long n,k;
  long long i,j;
  long long res=0;

  cin>>n>>k;
  vector<pair<long,long>> x(n);

  for(i=0;i<n;i++){
    cin>>x[i].first>>x[i].second;
    //cout<<x[i].first<<" "<<x[i].second<<endl;
  }
  sort(x.begin(),x.end());
                 
  j=0;
  for(i=0;j<k;i++){
    res=x[i].first;
    j+=x[i].second;
  }
  
  cout<<res<<endl;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n,m;
  const int64_t mod=1000000007;
  cin >> n >> m;
  if(abs(n-m)>1){
    cout << '0' << endl;
  }else{
    int64_t ans=1;
    for(int i=1;i<=n;i++){
      ans*=i;
      ans%=mod;
    }
    for(int i=1;i<=m;i++){
      ans*=i;
      ans%=mod;
    }
    if(m==n){
      ans*=2;
      ans%=mod;
    }
    cout << ans << endl;
  }
  return 0;
}
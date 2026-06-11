#include<iostream>
using namespace std;
int main(){
  long long mod=1000000007;
  long long n,m,i;
  cin >> n >> m;
  if(abs(n-m)>1){
    cout << 0 << endl;
    return 0;
  }
  long long ans=1;
  for(i=1;i<=n;i++){
    ans=ans*i%mod;
  }
  for(i=1;i<=m;i++){
    ans=ans*i%mod;
  }
  if(abs(n-m)==0){
    ans=ans*2%mod;
  }
  cout << ans%mod << endl;
}

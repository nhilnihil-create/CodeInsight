#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  int mod=1000000007;
  long long ans=1;
  for (int i=1; i<=n; i++){
    ans*=i;
    ans%=mod;
  }
  cout<<ans<<endl;
}
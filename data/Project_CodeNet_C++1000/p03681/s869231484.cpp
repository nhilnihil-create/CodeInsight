#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){ 
  int n,k;
  cin >> n>>k;
  if(abs(n-k)>=2){
    cout << 0;
    return 0;
  }
  long long ans=1,ans_1=1,answer=0;
  for(int i=1;i<=n;i++){
    ans*=i;
    ans%=1000000007;
  }
  
  for(int j=1;j<=k;j++){
    ans*=j;
    ans%=1000000007;
  }
  if(n==k){
    ans*=2;
  }
  ans%=1000000007;
  cout << ans;
}
  
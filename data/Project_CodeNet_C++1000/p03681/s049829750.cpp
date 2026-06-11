#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  if(abs(n-m)>1){
    cout << 0 << endl;
    return 0;
  }
  long long ans=1;
  for(long long i=1ll;i<=n;i++)
    ans=ans*i%1000000007ll;
  for(long long i=1ll;i<=m;i++)
    ans=ans*i%1000000007ll;
  if(n==m)
    ans=ans*2%1000000007ll;
  cout << ans << endl;
  return 0;
}
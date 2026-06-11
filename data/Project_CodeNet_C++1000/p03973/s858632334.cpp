#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

signed main() {
  int n;
  cin>>n;
  int a;
  cin>>a;
  int ans=a-1;
  int t=2;
  for(int i=1;i<n;i++){
    cin>>a;
    if(t==a)t++;
    else{
      ans+=(a-1)/t;
    }
  }
  cout<<ans;





  return 0;
}

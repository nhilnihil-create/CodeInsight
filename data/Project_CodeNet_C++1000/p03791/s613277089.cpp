#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD= 1000000007;
signed main() {
int n;
cin>>n;
int x[n];
for(int i=0;i<n;i++)cin>>x[i];
int t=0,ans=1;
for(int i=0;i<n;i++){
  t++;
  while(x[i]<t*2-1){
    ans=(ans*t)%MOD;
    t--;
  }
}
while(t){
  ans=(ans*t)%MOD;
  t--;
}
cout<<ans;
return 0;
}

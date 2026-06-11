#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}

auto factor(int n){
  map<int,int>res;
  for(int i=2;i*i<=n;i++){
      for(; n%i==0;n/=i) res[i]++;
  }
  if(n>1)res[n]++;
  return res;
}
////////////////////////////////////////////////////////////
signed main() {
  int n,m;
  cin>>n>>m;
  int ans=1;
  if(abs(n-m)==1){
    for(int i=n;i>=1;i--)ans=ans*i%MOD;
    for(int i=m;i>=1;i--)ans=ans*i%MOD;
    cout<<ans<<endl;
  }
  else if(n-m==0){
    for(int i=n;i>=1;i--)ans=ans*i%MOD;
    for(int i=m;i>=1;i--)ans=ans*i%MOD;
    ans=ans*2%MOD;
    cout<<ans<<endl;
  }
  else cout<<0<<endl;
}

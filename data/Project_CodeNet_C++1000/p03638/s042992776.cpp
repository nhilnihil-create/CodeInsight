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
  int h,w;
  cin>>h>>w;
  int n;
  cin>>n;
  int gyou=0,retu=0,dr=1;
  int ans[h][w];
  rep(i,h)rep(j,w)ans[i][j]=0;
  rep(i,n){
    int t;
    cin>>t;
    while(t>0){
      ans[gyou][retu]=i+1;
      retu+=dr;
      if(retu==w){
        retu=w-1;
        gyou++;
        dr*=-1;
      }
      if(retu==-1){
        retu=0;
        gyou++;
        dr*=-1;
      }
        t--;
    }
  }

  rep(i,h)rep(j,w){
    cout<<ans[i][j]<<' ';
    if(j==w-1)cout<<endl;
  }
}

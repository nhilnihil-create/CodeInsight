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
////////////////////////////////////////////////////////////
int keta(int n){
  int c=0;
  while(n>0){
    n/=10;
    c++;
  }
  return c;
}
signed main() {
  int n,k;
  cin>>n>>k;
  int ans=0;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  rep(i,n-1){
    int t=a[i]+a[i+1];
    if(t>k){
      if(t-k>a[i+1]){
        a[i+1]=0;
      }
      else{
        a[i+1]-=(t-k);
      }
      ans+=(t-k);
    }

  }
  cout<<ans<<endl;
}

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
  vector<int>d(k);
  rep(i,k)cin>>d[i];
  for(int i=n;i<=100000;i++){
    int t=i;
    bool b=true;
    while(t>0){
      rep(j,k){
        if(d[j]==t%10){
          b=false;
        }
      }
      t/=10;
    }
    if(b){
      ans=i;
      break;
    }
  }
  cout<<ans;
}

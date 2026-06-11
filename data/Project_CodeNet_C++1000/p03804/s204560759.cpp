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
  char a[n][n];
  char b[m][m];
  rep(i,n)rep(j,n)cin>>a[i][j];
  rep(i,m)rep(j,m)cin>>b[i][j];
  rep(i,n-m+1){
    rep(j,n-m+1){
      int bo=1;
      for(int x=i;x<=i+m-1;++x){
        for(int y=j;y<=j+m-1;++y){
          if(a[x][y]!=b[x-i][y-j])bo=0;
        }
      }
      if(bo){cout<<"Yes"<<endl;
            exit(0);}
    }
  }
  cout<<"No"<<endl;
}

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
  int a,b,x;
  cin>>a>>b>>x;
  if(a==0)cout<<b/x+1<<endl;
  else{
    cout<<b/x-(a-1)/x<<endl;
  }
}

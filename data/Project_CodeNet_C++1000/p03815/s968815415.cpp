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

signed main() {
  int x;
  cin>>x;
  int amari=x%11;
  if(amari>6)cout<<x/11*2+2;
  if(amari==0)cout<<x/11*2;
  else if(amari<=6)cout<<x/11*2+1;
}

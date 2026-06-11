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
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n){
    int t;
    cin>>t;
    a[t]++;
  }
  bool b=true;
  if(n%2==1){
    rep(i,n){
      if(i==0){if(a[i]!=1)b=false;}
      else if(i%2==0){
        if(a[i]!=2)b=false;
      }
    }
  }
  else{
    rep(i,n){
      if(i%2==1){
        if(a[i]!=2)b=false;
      }
    }
  }
  if(b) cout<<modpow(2,n/2)<<endl;
  else cout<<0<<endl;

}

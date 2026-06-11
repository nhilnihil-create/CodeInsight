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
  int n;
  cin>>n;
  vector<int>a(n);

  int sum=0;
  rep(i,n){
    cin>>a[i];
    sum+=a[i];
  }
  int h=sum/n;
  int h1=h+1;
  int t1=0,t2=0;
  rep(i,n){
    t1+=(h-a[i])*(h-a[i]);
    t2+=(h1-a[i])*(h1-a[i]);
  }
  cout<<min(t1,t2);

}

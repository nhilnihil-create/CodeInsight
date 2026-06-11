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
  int n;cin>>n;
  string a;
  cin>>a;
  vector<int>la(1+n);
  vector<int>lb(1+n);
  rep(i,n){
    if(a[i]==')'){la[i+1]=la[i]+1;lb[i+1]=lb[i];}
    else {lb[i+1]=lb[i]+1;la[i+1]=la[i];}
  }
  int l=0;
  rep(i,n+1)l=max(la[i]-lb[i],l);

  vector<int>ra(1+n);
  vector<int>rb(1+n);
  rep(i,n){
    if(a[n-1-i]==')'){ra[i+1]=ra[i]+1;rb[i+1]=rb[i];}
    else {rb[i+1]=rb[i]+1;ra[i+1]=ra[i];}
  }
  int r=0;
  rep(i,n+1)r=max(rb[i]-ra[i],r);
  rep(i,l)cout<<'(';
  cout<<a;
  rep(i,r)cout<<')';
}

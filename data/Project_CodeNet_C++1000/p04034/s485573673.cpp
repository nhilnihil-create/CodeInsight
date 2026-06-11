#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  int n,m;
  cin>>n>>m;
  int x[m],y[m],sum[n];
  bool pos[n];
  for(int i=0;i<m;i++){
    cin>>x[i]>>y[i];
    x[i]--;y[i]--;
  }
  for(int i=0;i<n;i++){
    sum[i]=1;
    pos[i]=false;
  }
  pos[0]=true;
  for(int i=0;i<m;i++){
    if(pos[x[i]]) pos[y[i]]=true;
    sum[x[i]]--;sum[y[i]]++;
    if(sum[x[i]]==0) pos[x[i]]=false; 
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(pos[i])ans++;
  }
  cout<<ans<<endl;
  return 0;
}
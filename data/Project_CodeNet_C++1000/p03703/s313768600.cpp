#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll dat[800005];
ll n;
void init(ll n_){
n=1;
  while(n<=n_)
    n*=2;
}
void add(ll k,ll a){
k+=n-1;
  dat[k]+=a;
  while(0<k){
  k=(k-1)/2;
    dat[k]=dat[2*k+1]+dat[2*k+2];
  }
}
ll query(ll a,ll b,ll k,ll l,ll r){
if(a<=l && r<=b)
  return dat[k];
  else if(b<=l || r<=a)
    return 0;
  else{
  ll val=query(a,b,2*k+1,l,(l+r)/2);
    ll var=query(a,b,2*k+2,(l+r)/2,r);
    return (val+var);
  }

}
ll N,K;
int main(){
  cin>>N>>K;init(N);
  vector<ll>a(N+1);a[0]=0;
  for(int i=1;i<=N;i++){
  ll x;cin>>x;x-=K;
    a[i]=a[i-1]+x;
  }vector<ll>b(N+1);
  for(int i=0;i<=N;i++)
    b[i]=a[i];
  sort(b.begin(),b.end());
  map<ll,ll>M;ll x=0;M[b[0]]=0;
  for(int i=1;i<=N;i++)
    if(b[i]!=b[i-1]){x++;M[b[i]]=x;}
  else{}
  for(int i=0;i<=N;i++)
    a[i]=M.at(a[i]);
  ll ans=0;
  for(int i=0;i<=N;i++){
  ll sum=query(0,a[i]+1,0,0,n);
    ans+=sum;
    add(a[i],1);
  }
  cout<<ans<<endl;
  return 0;
}
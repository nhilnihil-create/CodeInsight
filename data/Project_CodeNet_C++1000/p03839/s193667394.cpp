#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using data=pair<ll,ll>;
#define Rep(i,N) for(i=0;i<N;i++)
#define mod 1000000007

long mmid(long a,long b,long c){return a<b?(b<c?b:max(a,c)):(b>c?b:min(a,c));}

ll modinv(ll a) {
  ll b=mod,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+mod)%mod;
}

ll moddevide(ll a,ll b){return (a*modinv(b))%mod;}
 
ll modncr(ll n,ll r){
  ll i,plus=1;
  Rep(i,r){
    plus=(plus*(n-i))%mod;
    plus=moddevide(plus,i+1);
  }
  return plus;
}

ll euclidean_gcd(ll a, ll b) {
  if(a<b) return euclidean_gcd(b, a);
  ll r;
  while ((r=a%b)){a=b;b=r;}
  return b;
}

int main(){
  ll i,j,N,K,m=0,ans,pl=0,mi=0;
  cin>>N>>K;
  vector<ll> a(N),plus(N,0),minus(N,0);
  Rep(i,N){
    cin>>a[i];
    if(a[i]>0)m+=a[i];
    if(i<K){
      if(i==0){
        if(a[i]>=0){plus[i]=a[i];}
        else{minus[i]=a[i];}
      }else{
        if(a[i]>=0){plus[i]=plus[i-1]+a[i];minus[i]=minus[i-1];}
        else{minus[i]=minus[i-1]+a[i];plus[i]=plus[i-1];}
      }
    }else{
      pl=plus[i-1];mi=minus[i-1];
      if(a[i-K]>=0){pl-=a[i-K];}
      else{mi-=a[i-K];}
      if(a[i]>=0){pl+=a[i];}
      else{mi+=a[i];}
      plus[i]=pl;minus[i]=mi;
      //cout<<pl<<" "<<mi<<endl;
    }
  }
  ans=min(plus[K-1],0-minus[K-1]);
  for(i=K;i<N;i++){
    if(ans>min(plus[i],0-minus[i]))ans=min(plus[i],0-minus[i]);
  }
  cout<< m-ans <<endl;
  return 0;
}
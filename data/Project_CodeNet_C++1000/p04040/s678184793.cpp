#include <iostream>
#include<cstdio>
#include<algorithm>
const long long mod=1e9+7;
typedef long long ll;
using namespace std;

ll f[1000010],revf[1000010];//数组大小至少要为1e5*2

ll qpow(ll a,ll b){
  ll ret=1;
  while(b){
    if(b&1) ret=(ret*a)%mod;
    a=(a*a)%mod;
    b>>=1;
  }
  return ret;
}

void init(){
  f[0]=1; revf[0]=qpow(f[0],mod-2);
  for(ll i=1;i<1000010;i++){
    f[i]=i*f[i-1]%mod;
    revf[i]=qpow(f[i],mod-2);
  }
}

ll C(ll n,ll m){
  return (f[n]*revf[m])%mod*revf[n-m]%mod;
}

ll count_ways(ll a,ll b,ll c,ll d){
  ll tot=(c-a)+(d-b);
  ll down=(c-a);
  ll ret=C(tot,down);
  return ret;
}

int main()
{
    init();
    ll h,w,a,b;
    cin>>h>>w>>a>>b;
    ll tot=count_ways(1,1,h,w);
    for(ll i=1;i<=b;i++){
        ll tmp=count_ways(1,1,h-a,i)*count_ways(h-a+1,i,h,w)%mod;
        while(tot<tmp) tot+=mod;//防止出现负数
        tot=(tot-tmp)%mod;
    }
    cout<<tot<<endl;
    return 0;
}
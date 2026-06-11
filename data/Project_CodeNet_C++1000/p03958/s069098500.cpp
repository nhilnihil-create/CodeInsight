#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef long double ld;
const ll MOD=1000000007;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
long long gcd(long long a,long long b){
    ll gcdmax=max(a,b);
    ll gcdmin=min(a,b);
    while(true){
        if(gcdmax%gcdmin==0)break;
        else gcdmax%=gcdmin;
        swap(gcdmin,gcdmax);
    }
    return gcdmin;
}
ll powerup(ll N,ll P,ll M){
    if(P==0)return 1;
    else if(P%2==0){
        ll t=powerup(N,P/2,M);
        return t*t%M;
    }
    else return N*powerup(N,P-1,M)%M;
}
vector<ll> find_divisor(ll N){
  ll k=1;
  while(k*k<=N){
    k++;
  }
  vector<ll> A(1);
  rep(i,k){
    if(i==1)A.at(0)=1;
    else if(i>=2){
      if(N%i==0)A.push_back(i);
    }
  }
  ll t=0;
  t=A.size();
  rep(i,t){
    if(A.at(t-i-1)*A.at(t-i-1)!=N)A.push_back(N/A.at(t-1-i));
  }
  return A;
}
int main()
{
  ll L,K;
  cin>>L>>K;
  vector<ll> A(K);
  rep(i,K)cin>>A.at(i);
  ll ans=0;
  ll Z=0;
  rep(i,K)ans+=max(Z,(A.at(i)*2-L-1));
  cout<<ans<<endl;
}
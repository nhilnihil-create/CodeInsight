#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

ll moP(ll x, ll n) {
  ll res=1;
  while(n>0) {
    if(n&1) moC(res, *, x);
    moC(x, *, x);
    n>>=1;
  }
  return res;
}


int main(void) {
  ll i, j, k;
  ll N;
  cin >> N;
  ll a[MAX], d[MAX];
  ll s=0;
  
  for(i=0; i<N; i++) {
    cin >> a[i];
    s+=a[i];
  }
  
  ll f=1;
  
  if(s%(N*(N+1)/2)!=0) f=0;
  
  ll K=s/(N*(N+1)/2);
  for(i=0; i<N; i++) d[(i+1)%N]=a[(i+1)%N]-a[i%N];
  for(i=0; i<N; i++) d[i]-=K;
  
  
  k=0;
  for(i=0; i<N; i++) {
    if(d[i]>0) f=0;
    
    ll t=abs(d[i]);
    if(t%N!=0) f=0;
    
    k+=t/N;
  }
  
  if(k!=K) f=0;
  
  
  if(f) pt("YES");
  else pt("NO");
  
  
  
}




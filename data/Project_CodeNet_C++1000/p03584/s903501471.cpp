#include <bits/stdc++.h>
#include <string>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) (a)=max(a, b);
#define chmin(a, b) (a)=min(a, b);
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;


/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/



int main(void) {
  ll i, j, k;
  
  ll N, K;
  cin >> N >> K;
  ll a[MAX], b[MAX];
  
  for(i=0; i<N; i++) cin >> a[i] >> b[i];
  
  ll ans=0;
  for(i=0; i<N; i++) if((K|a[i])==K) ans+=b[i];
  
  for(i=0; i<=30; i++) {
    if(!(K>>i&1)) continue;
    ll S=(K>>(i+1))<<(i+1) | ((1<<i)-1);
    ll t=0;
    for(j=0; j<N; j++) if((S|a[j])==S) t+=b[j];
    chmax(ans, t);
  }
  
  pt(ans);
  
}




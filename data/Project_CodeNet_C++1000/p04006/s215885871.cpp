#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MOD=1e9+7;
static const ll MAX=101010;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/



int main(void) {
  ll i, j, k, l;
  
  ll N, x;
  cin >> N >> x;
  ll a[2222], b[2222];
  
  for(i=0; i<N; i++) cin >> a[i];
  for(i=0; i<N; i++) b[i]=INF;
  
  ll ans=INF;
  for(k=0; k<N; k++) {
    ll t=k*x;
    
    for(i=0; i<N; i++) chmin(b[i], a[(i-k+N)%N]);
    for(i=0; i<N; i++) t+=b[i];
    
    chmin(ans, t);
  }
  
  pt(ans);
  
  
}



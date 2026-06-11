#include <bits/stdc++.h>
#include <string>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) (a)=max(a, b)
#define chmin(a, b) (a)=min(a, b)
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
  ll a[MAX]={};
  ll s[MAX]={}, t[MAX]={};
  
  for(i=1; i<=N; i++) cin >> a[i];
  for(i=1; i<=N; i++) s[i]=s[i-1]+a[i];
  for(i=1; i<=N; i++) t[i]=t[i-1]+(a[i]>0 ? a[i] : 0);
  
  ll ans=0;
  for(i=1; i<=N-K+1; i++) {
    ll u=s[i+K-1]-s[i-1];
    ll sco=t[i-1]+(u>0?u:0)+(t[N]-t[i+K-1]);
    chmax(ans, sco);
  }
  
  pt(ans);
  
}




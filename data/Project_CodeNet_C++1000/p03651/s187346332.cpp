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

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/


ll gcd(ll a, ll b) {
  if(b==0) return a;
  else return gcd(b, a%b);
}


int main(void) {
  ll i, j, k;
  ll N, K;
  cin >> N >> K;
  
  ll g=0;
  ll ma=0;
  for(i=0; i<N; i++) {
    ll a;
    cin >> a;
    g=gcd(g, a);
    chmax(ma, a);
  }
  
  if(ma>=K && K%g==0) pt("POSSIBLE");
  else pt("IMPOSSIBLE");
  
}


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




int main(void) {
  ll N;
  cin >> N;
  ll i;
  ll a[MAX];
  P p[MAX];
  
  for(i=0; i<N; i++) {
    ll t;
    cin >> t;
    p[i].first=t;
    p[i].second=i;
  }
  sort(p, p+N);
  
  for(i=0; i<N; i++) {
    ll idx=p[i].second;
    a[idx]=i;
  }
  
  ll ans=0;
  for(i=0; i<N; i+=2) {
    if(i%2!=a[i]%2) ans++;
  }
  
  pt(ans);
}

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
  ll N, L;
  cin >> N >> L;
  ll i;
  ll a[MAX];
  ll s=0;
  
  for(i=0; i<N; i++) {
    cin >> a[i];
  }
  
  
  ll key=-1;
  for(i=0; i<N-1; i++) {
    if(a[i]+a[i+1]>=L) key=i;
  }
  
  if(key==-1) {
    pt("Impossible");
    return 0;
  }
  
  vector<ll> v;
  for(i=0; i<key; i++) v.push_back(i);
  for(i=N-2; i>key; i--) v.push_back(i);
  v.push_back(key);
  
  pt("Possible");
  for(i=0; i<N-1; i++) pt(v[i]+1);
}

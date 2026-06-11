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
  
  ll D[2];
  cin >> D[0] >> D[1];
  
  vector<P> v;
  for(i=0; i<D[0]; i++) {
    ll p;
    cin >> p;
    v.push_back(P(p, 0));
  }
  
  for(i=0; i<D[1]; i++) {
    ll q;
    cin >> q;
    v.push_back(P(q, 1));
  }
  
  sort(v.begin(), v.end());
  
  ll ans=0;
  ll pos[2]={};
  for(i=0; i<D[0]+D[1]; i++) {
    ll c=v[i].first;
    ll r=v[i].second;
    
    ans+=(D[1-r]+1-pos[1-r])*c;
    pos[r]++;
  }
  
  pt(ans);
}



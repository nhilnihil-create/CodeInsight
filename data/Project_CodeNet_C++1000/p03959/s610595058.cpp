#include <bits/stdc++.h>
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static const ll MOD=1e9+7;
ll max(ll a, ll b) {return a>b?a:b;}
ll min(ll a, ll b) {return a<b?a:b;}



int main(void) {
  ll N;
  cin >> N;
  ll a[MAX]={}, b[MAX]={};
  ll h[MAX]={};
  ll i;
  
  ll ma=0, mb=0;
  for(i=1; i<=N; i++) {
    cin >> a[i];
    chmax(ma, a[i]);
  }
  for(i=1; i<=N; i++) {
    cin >> b[i];
    chmax(mb, b[i]);
  }
  
  if(ma!=mb) {
    pt(0);
    return 0;
  }
  
  ll H=ma;
  ll ida=0, idb=0;
  for(i=1; i<=N; i++) {
    if(a[i]==H) {
      ida=i;
      break;
    }
  }
  
  for(i=N; i>=1; i--) {
    if(b[i]==H) {
      idb=i;
      break;
    }
  }
  
  if(idb<ida) {
    pt(0);
    return 0;
  }
  
  ll ans=1;
  for(i=1; i<ida; i++) {
    if(a[i-1]==a[i]) {
      moC(ans, *, a[i]);
    }
  }
  
  for(i=ida+1; i<=idb-1; i++) {
    moC(ans, *, H);
  }
  
  for(i=N; i>idb; i--) {
    if(b[i]==b[i+1]) {
      moC(ans, *, b[i]);
    }
  }
  
  pt(ans);
}







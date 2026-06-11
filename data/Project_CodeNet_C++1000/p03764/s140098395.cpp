#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<ll,ll> pii;
typedef vector<pii> vpii;
typedef pii point;
using namespace std;
const ll INF = (1ll<<32);
const ll MOD = 1000000007;

int main() {
  ll n,m; cin>>n>>m;
  vi x(n),y(m); REP(i,n) cin>>x[i]; REP(i,m) cin>>y[i];
  vi w(n-1),h(m-1);
  REP(i,n-1) w[i]=x[i+1]-x[i];
  REP(i,m-1) h[i]=y[i+1]-y[i];
  ll a=0,b=0;
  FOR(i,1,n) a=(a+w[i-1]*i*(n-i))%MOD;
  FOR(i,1,m) b=(b+h[i-1]*i*(m-i))%MOD;
  cout<<(a*b)%MOD<<endl;
}

// 7565

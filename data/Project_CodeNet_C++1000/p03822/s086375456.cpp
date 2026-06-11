#include <bits/stdc++.h>
#include <string>
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

ll N;
vector<ll> g[MAX];

ll dfs(ll u) {
  vector<ll> v;
  ll i;
  ll nch=g[u].size();
  
  for(i=0; i<nch; i++) {
    v.push_back(dfs(g[u][i]));
  }
  sort(v.rbegin(), v.rend());
  
  ll res=0;
  for(i=0; i<nch; i++) {
    chmax(res, i+1+v[i]);
  }
  
  return res;
}

int main(void) {
  ll i, j, k;
  
  cin >> N;
  
  for(i=1; i<N; i++) {
    ll a;
    cin >> a;
    a--;
    g[a].push_back(i);
  }
  
  pt(dfs(0));
  
}


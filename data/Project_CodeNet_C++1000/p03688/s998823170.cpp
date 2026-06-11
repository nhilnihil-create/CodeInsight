#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

void yes(){
  cout << "Yes" << endl;
  exit(0);
}

void no(){
  cout << "No" << endl;
  exit(0);
}

int main(){
  ll n; cin >> n;
  vector<ll> a(n);
  ll maxi = 0, mini = 1e18;
  REP(i,n) {
    cin >> a[i];
    maxi = max(maxi,a[i]);
    mini = min(mini,a[i]);
  }
  if(maxi-mini>1) no();
  if(maxi==mini){
    if(maxi==n-1 || 2*maxi<=n) yes();
    else no();
  }
  
  ll alone = 0;
  REP(i,n) if(a[i]==mini) alone++;
  if(alone<maxi && 2*(maxi-alone)<=n-alone) yes();
  else no();
}
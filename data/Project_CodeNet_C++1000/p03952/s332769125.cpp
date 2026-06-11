#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()

void yes(vector<ll>& ans){
  cout << "Yes" << endl;
  ll m = ans.size();
  REP(i,m) cout << ans[i] << endl;
}

void no(){
  cout << "No" << endl;
  exit(0);
}

int main(){
  ll N, x; cin >> N >> x;
  if(x==1 || x==2*N-1) no();
  vector<ll> ans(2*N-1);
  if(x==2) REP(i,2*N-1) ans[(N-2+i)%(2*N-1)] = i+1;
  else REP(i,2*N-1) ans[(2*N-1+ N-x+i)%(2*N-1)] = i+1;
  yes(ans);
}


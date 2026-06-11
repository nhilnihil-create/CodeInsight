#include<bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<int >    vecint;
typedef vector<vector<int> >  vec2int;
typedef vector<ll >     vecll;
typedef vector<string > vecstr;
typedef vector<bool > vecbool;
typedef vector<bool > vecbool;
////////////////////////////////////////////////
int main()
{
  ll n, a, b; cin >> n >> a >> b;
  vecll x(n,0);
  REP(i,n)cin >> x[i];
  ll ans = 0;
  REP(i,n - 1){
    ans += min(a*(x[i + 1] - x[i]), b);
  }
  cout << ans << endl;
}

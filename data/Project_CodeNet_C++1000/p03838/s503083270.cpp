#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<bool>    vecbool;
typedef vector<int>     vecint;
typedef vector<ll>      vecll;
typedef vector<string>  vecstr;
typedef vector<vecint>  vec2int;
typedef vector<vecbool> vec2bool;
int dx[4] {-1,+1, 0, 0};
int dy[4] { 0, 0,-1,+1};
int main()
{
  ll x, y; cin >> x >> y;
  ll z = 2e9 + 1;
  ll a =   y - x;
  ll b = - y - x + 1;
  ll c =   x - y + 2;
  ll d =   x + y + 1;
  if(a < 0)a = z;
  if(b < 0)b = z;
  if(c < 0)c = z;
  if(d < 0)d = z;
  ll e = min(a,b);
  ll f = min(c,d);
  cout << min(e,f) << endl;
}

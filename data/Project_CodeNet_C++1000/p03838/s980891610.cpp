#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
ll calc(ll x,ll y){
  if(x<y){
    return y - x;
  }else if(x==y){
    return 0;
  }
  return 1e10;
}
int main()
{
  ll x, y;
  cin >> x >> y;
  ll cnt = 0;
  cnt = min(calc(x, y), calc(-x, y) + 1);
  ll cnt2 = min(calc(x, -y) + 1, calc(-x, -y) + 2);
  cnt = min(cnt, cnt2);
  cout << cnt << endl;
}
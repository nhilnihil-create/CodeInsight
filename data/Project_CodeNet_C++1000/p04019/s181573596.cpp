#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0)
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MAXR 100000
#define PI acos(-1.0)

int main()
{
  string S; cin >> S;
  ll dx = 0, dy = 0;
  ll n = 0, s = 0, w = 0, e = 0;
  REP(i, SIZE(S)) {
    if (S[i] == 'N') n++;
    else if (S[i] == 'S') s++;
    else if (S[i] == 'W') w++;
    else if (S[i] =='E') e++;
  }

  string ans;
  if (n == 0 && 0 < s) ans = "No";
  else if (s == 0 && 0 < n) ans = "No";
  else if (w == 0 && 0 < e) ans = "No";
  else if (e == 0 && 0 < w) ans = "No";
  // else if ((n - s) % 2 == 0 && (w - e) % 2 == 0) ans = "Yes";
  // else ans = "No";
  else ans = "Yes";

  cout << ans << endl;
  return 0;
}

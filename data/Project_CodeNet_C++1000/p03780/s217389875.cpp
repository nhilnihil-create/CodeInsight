#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<map>
#include<functional>
#include<set>

#pragma region
using namespace std;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define PB(a,n) FOR(i,0,n){ll buf; scanf("%lld",&buf); a.pb(buf); }
#define LOWER(a,x) lower_bound(ALL(a), x) - a.begin() - 1;
#define COUNT(a,x)  upper_bound(ALL(a), x) - lower_bound(ALL(a), x);
#define MCOUNT(a,x,y) upper_bound(ALL(a), y) - lower_bound(ALL(a), x);
#define INF 111111111111111111
#define MOD 1000000007
#define pb push_back
#define F first
#define S second
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, ans = 0, sum = 0, cnt = 0, tmp = 0, ma = 0, mi = 0;
string s;
bool flag, ok;
ll dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
ll ddx[8] = { 1,-1,0,0,1,1,-1,-1 }, ddy[8] = { 0,0,1,-1,1,-1,1,-1 };
#pragma endregion
#define MAX 111111


bitset<5001> dp1[5005], dp2[5005];
ll sm[5555];
int main(void) {
  ll k;
  vll a;
  cin >> n >> k;
  PB(a, n);
  FOR(i, 0, n) sum += a[i];

  dp1[0][0] = 1;
  FOR(i, 1, n + 1) {
	if (a[i - 1] < k) {
	  dp1[i] = dp1[i - 1] | dp1[i - 1] << a[i - 1];
	}
	else {
	  dp1[i] = dp1[i - 1];
	}
  }
  dp2[0][0] = 1;
  FOR(i, 1, n + 1) {
	if (a[n - i] < k) {
	  dp2[i] = dp2[i - 1] | dp2[i - 1] << a[n - i];
	}
	else {
	  dp2[i] = dp2[i - 1];
	}
  }

  FOR(i, 1, n + 1) {
	if (a[i - 1] >= k) {
	  if (!dp1[i - 1].any() && !dp2[n - i].any()) ans++;
	  continue;
	}

	FOR(j, 1, k) sm[j] = 0;
	FOR(j, 1, k) sm[j] = dp2[n - i][j] ? sm[j - 1] + 1 : sm[j - 1];

	flag = false;
	FOR(j, k - a[i - 1], k) if (dp1[i - 1][j]) flag = true;
	FOR(j, k - a[i - 1], k) if (dp2[n - i][j]) flag = true;
	FOR(j, 0, k) {
	  if (dp1[i - 1][j]) {
		if ((sm[k - 1 - j] - sm[max(0LL, k - a[i - 1] - j)]) != 0 || dp2[n-i][max(0LL, k - a[i - 1] - j)] ) {
		  flag = true;
		  break;
		}
	  }
	}
	if (!flag) ans++;
  }

  if (sum < k) {
	cout << n << endl;
  }
  else {
	cout << ans << endl;
  }

  return 0;
}
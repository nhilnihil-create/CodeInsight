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
#include<numeric>

#pragma region
using namespace std;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define rep(i,n) FOR(i,0LL,n)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define rrep(i,n) RFOR(i,0LL,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define COUNT(a,y,x) upper_bound(all(a), y) - lower_bound(all(a), x)
#define UNIQUE(a) sort(all(a)); a.erase(unique(all(a)), a.end())
#define SUM(a) accumulate(all(a),0LL)
#define pb push_back
#define endl '\n'
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef map<ll, ll> MAP;
const ll inf = 2222222222222222222LL;
const ll mod = 1000000007LL;

ll n = 0, m = 0, ans = 0, cnt = 0, tmp = 0, ma = -inf, mi = inf;
string s;
bool ok = true, flag = false;
ll dx[5] = { 1,-1,0,0,0 }, dy[5] = { 0,0,1,-1,0 };
ll ddx[9] = { 1,-1,0,0,1,1,-1,-1,0 }, ddy[9] = { 0,0,1,-1,1,-1,1,-1,0 };
#pragma endregion
#define MAX 222222




int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  vpll v;
  pll p;
  rep(i, n) {
	cin >> tmp;
	ans += tmp;
	p.first = tmp, p.second = 0;
	v.pb(p);
  }
  rep(i, m) {
	cin >> tmp;
	ans += tmp;
	p.first = tmp, p.second = 1;
	v.pb(p);
  }
  sort(all(v));
  ma = (n + 1)*(m + 1) - 1;
  ll cnt = ma - n - m;
  ll k = n + m;
  rep(i, k) {
	if (v[i].second == 0) {
	  ans += v[i].first * min(cnt, m);
	  cnt -= m;
	  n--;
	}
	else {
	  ans += v[i].first * min(cnt, n);
	  cnt -= n;
	  m--;
	}
	if (cnt <= 0) break;
  }

  cout << ans << endl;

  return 0;
}
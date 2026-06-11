#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
using P = pair<ll, ll>;
using Vec = vector<ll>;
using VecP = vector<P>;
#define REP(i, m, n) for(ll (i) = (m); (i) < (n); ++(i))
#define REPN(i, m, n) for(ll (i) = (m); (i) <= (n); ++(i))
#define REPR(i, m, n) for(ll (i) = (m); (i) >= (n); --(i))
#define rep(i, n) REP(i, 0, n)
#define repn(i, n) REPN(i, 1, n)
#define repr(i, n) REPR(i, n, 0)
#define repnr(i, n) REPR(i, n, 1)
#define co(n) cout << (n) << endl
#define cosp(n) cout << (n) << ' '
#define setp(n) cout << fixed << setprecision(n);
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second

const ll INF = 1e9+1;
const ll LINF = 1e18+1;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-9;

int main(void){
	ll n;
	cin >> n;
	Vec a(n);
	rep(i, n) cin >> a[i];

	ll mini = LINF, maxi = 0LL;
	for(ll i : a){
		mini = min(mini, i);
		maxi = max(maxi, i);
	}
	if(maxi- mini >= 2){
		puts("No");
		return 0;
	}else if(maxi == mini){
		if(maxi == n-1 || maxi <= n/2) puts("Yes");
		else puts("No");
		return 0;
	}

	ll cntMin = 0, cntMax = 0;
	for(ll i : a){
		if(i == mini) cntMin++;
		else cntMax++;
	}
	if(maxi >= cntMin+1 && maxi <= cntMin+cntMax/2) puts("Yes");
	else puts("No");

	return 0;
}

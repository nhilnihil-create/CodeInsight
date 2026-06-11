#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define mrep(i,from,n) for(int i = from; i < n; i++)
#define mreps(i,from,n) for(int i = from; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(all(x), val), x.end())
typedef long long ll;
typedef pair<int, int> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll MOD = 1000000007;
int INF = 1001001001;

void solve()
{
	int n; cin >> n;
	vector<ll> t(n), a(n);
	rep(i, n)cin >> t[i] >> a[i];
	
	ll vt = t[0];
	ll va = a[0];
	
	rep(i, n)
	{
		if (vt * a[i] == va * t[i]) continue;

		ll x = max((vt+t[i]-1)/t[i],(va+a[i]-1)/a[i]);
		vt = x * t[i];
		va = x * a[i];
	}
	ll ans = vt + va;
	cout << ans << endl;
    return;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}

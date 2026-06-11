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
#define ERASE(x,val) x.erase(remove(ALL(x), val), x.end())
typedef long long ll;
typedef pair<ll, ll> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll MOD = 1000000007;

void solve()
{	
	int n; cin >> n;
	vector<int> l(2*n);
	rep(i, 2*n) cin >> l[i];
	sort(all(l),greater<int>());
	int ans = 0;
	rep(i, n)ans += l[2*i+1];
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

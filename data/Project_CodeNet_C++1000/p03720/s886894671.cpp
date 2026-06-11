#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f40;
const long long mod=2e9+7;
const long double PI = acos(0);
// }}} End Header
int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> ans;
	rep(i,m){
		int a, b;
		cin >> a >> b;
		ans[a]++;
		ans[b]++;
	}
	loop(i, 1, n+1) cout << ans[i] << endl;
	return 0;
}
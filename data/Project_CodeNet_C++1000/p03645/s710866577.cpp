#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))


const double pi = 4*atan(1);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 200005;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin >> n >> m;

	vector<bool> reaches(n);
	vector<vector<int>> adj(n,vector<int>());

	while(m--){
		int a, b;
		cin >> a >> b;
		a--;b--;

		if (b == n-1) {
			reaches[a]=true;
		}
		if (a == 0) {
			adj[a].pb(b);
		}
	}

	for (auto v : adj[0]) {
		if (reaches[v]) {
			cout << "POSSIBLE\n";
			return 0;
		}
	}


	cout << "IMPOSSIBLE" << "\n";

}

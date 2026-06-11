#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define pp pop_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const double pi = acos(-1.0), eps = 1e-9;
const int N = 1e5 + 111, inf = 1e9, mod = 1e9 + 7;

int n, k, a[N], ans, dp[N];
bool used[N], ok[N];
vector <int> g[N], ord;

bool cmp(int x, int y){
	return dp[x] < dp[y];
}

void dfsa(int v){
	ok[v] = 1;
	for(auto to : g[v]){
		if(ok[to])
			continue;
		dp[to] = dp[v] + 1;
		dfsa(to);
	}
}

void dfsaa(int v){
	for(auto to : g[v]){
		dp[to] = dp[v] + 1;
		dfsaa(to);
	}
}

int main(){
	srand(time(NULL));

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cout << setprecision(10) << fixed;

	cin >> n >> k;
	
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	if(a[1] != 1)
		a[1] = 1, ans = 1;

	for(int i = 2; i <= n; ++i)
		g[a[i]].pb(i);

	dfsaa(1);

	for(int i = 1; i <= n; ++i)
		ord.pb(i);

	sort(all(ord), &cmp);

	
	for(int i = 0; i < n; ++i){
		int x = ord[n - i - 1];
		if(!ok[x] && dp[x] > k){
			int root = x;
			for(int j = 2; j <= k; ++j)
				root = a[root];
			a[root] = 1;
			ans++;
			dp[root] = 1;
			dfsa(root);	
		}
	}

	cout << ans;

	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;
	return 0;
}
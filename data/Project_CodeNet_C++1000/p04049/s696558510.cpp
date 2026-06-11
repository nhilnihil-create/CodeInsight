#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <complex>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>

#define ft first
#define sc second
#define pb push_back
#define len(v) (int)v.size()
// #define int ll

using namespace std;
typedef long long ll;
typedef long double ld;

vector<vector<int>> g;
vector<vector<int>> lst;

void dfs(int v, int p, int st, int dl = 0){
	lst[st][v] = dl;
	for (auto x : g[v]) {
		if(x == p) 
			continue;
		dfs(x, v, st, dl + 1);
	}
}

signed main() {
	#ifdef PC
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	g = vector<vector<int>> (n);
	lst = vector<vector<int>> (n, vector<int> (n, 0));

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	for (int i = 0; i < n; i++) {
		dfs(i, i, i);
	}

	vector<bool> used(n, 0);
	vector<bool> del(n, 0);
	vector<int> cnt(n, 0);
	set<int> have;

	for (int i = 0; i < n; i++) {
		if(len(g[i]) == 1) {
			have.insert(i);
			used[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(lst[i][j] > k)
				cnt[i]++;
		}
	}

	int ans = 0;
	while(1) {
		int maxxi = -1;
		// cout << ans << endl;
		// for (auto x : have)
		// 	cout << x << " ";
		// cout << endl;
		for (auto u : have) {
			if(cnt[u] == 0) 
				continue;
			if(maxxi == -1) 
				maxxi = u;
			if(cnt[u] > cnt[maxxi]) 
				maxxi = u;
		}
		if(maxxi == -1)
			break;
		ans++;
		del[maxxi] = 1;
		have.erase(maxxi);
		for (int i = 0; i < n; i++) {
			if(lst[i][maxxi] > k) 
				cnt[i]--;
		}

		int add = -1;
		int neww = 0;
		for (int i = 0; i < n; i++) {
			if(used[i]) 
				continue;
			int now = 0;
			for (auto x : g[i]) {
				if(del[x]) 
					continue;
				now++;
			}
			if(now <= 1) {
				add = i;
				break;
			}
		}
		if(neww > 1) 
			return -1;
		if(add == -1)
			continue;
		used[add] = 1;
		have.insert(add);
	}
	cout << ans << endl;
}
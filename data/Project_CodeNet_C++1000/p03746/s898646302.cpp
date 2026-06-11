#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 1e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, m;
vector<int> graph[maxn];
deque<int> ans;
bool visited[maxn], found;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		if (ans.empty()) {
			ans.pb(u);
			ans.pb(v);
			visited[u] = true;
			visited[v] = true;
		}

		graph[u].pb(v);
		graph[v].pb(u);
	}

	while (true) {
		bool flag = false;
		for (int i : graph[ans.front()]) {
			if (!visited[i]) {
				ans.pf(i);
				visited[i] = true;
				flag = true;
				break;
			}
		}
		for (int i : graph[ans.back()]) {
			if (!visited[i]) {
				ans.pb(i);
				visited[i] = true;
				flag = true;
				break;
			}
		}
		if (!flag) {
			break;
		}
	}
	cout << ans.size() << endl;
	for (int i : ans) {
		cout << i + 1 << ' ';
	}
	cout << endl;
}


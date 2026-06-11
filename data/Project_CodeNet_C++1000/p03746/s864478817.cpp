#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
 
const int N = 1e5 + 123;
int n, m, used[N];
vi adj[N];
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> m;
	int l, r;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
		l = x, r = y;
	}
	used[l] = used[r] = 1;
	deque <int> path;
	path.push_front(l);
	path.pb(r);
	while (true) {
		int changes = 0;
		for (int to : adj[l]) {
			if (!used[to]) {
				l = to;
				used[l] = 1;
				changes = 1;
				path.push_front(l);
				break;
			}
		}
		for (int to : adj[r]) {
			if (!used[to]) {
				r = to;
				used[r] = 1;
				changes = 1;
				path.pb(r);
				break;
			}
		}
		if (!changes) {
			break;
		}
	}
	cout << path.size() << '\n';
	for (int i : path) {
		cout << i << ' ';
	}
}

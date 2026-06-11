// IOI 2021
#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
 
////////////////////////////////////////////////////////////////////
 
const int N = 1e5 + 5;

vector<int> G[N];

int Grundy(int v, int p = 0) {
	int g = 0;
	for (int u : G[v]) if (u != p) g ^= Grundy(u, v) + 1;
	return g;
}

int main() {
 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937 Rnd(time(0));

	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int v, u; cin >> v >> u;
		G[v].push_back(u), G[u].push_back(v);
	}
	cout << (Grundy(1) ? "Alice" : "Bob") << endl;

	return 0;
}

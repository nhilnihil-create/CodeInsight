#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

//1 - - 4 5 - - - 9 - - 12
const int LOG = 20;
int main() {
	int n;
	cin >> n;
	vector <int> x(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	int l;
	cin >> l;
	vector<vector<int>> nxt(n + 1, vector<int>(LOG, MOD));
	int r = n;
	for (int i = n - 1; i >= 1; i--) {
		while(x[r] > x[i] + l) r--;
		nxt[i][0] = r;
	}
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			if (nxt[i][j - 1] != MOD)
				nxt[i][j] = nxt[nxt[i][j-1]][j-1];
		}
	}
	//debug(nxt);
	int q;
	cin >> q;
	while(q--) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		int ans = 0;
		while (a != b) {
			int cur = -1;
			for (int j = 0; j < LOG; j++) {
				if (nxt[a][j] > b) {
					cur = j - 1;
					break;
				}
			}
			if (cur == -1) {
				ans += 1;
				break;
			}
			ans += (1 << cur);
			a = nxt[a][cur]; 
		}
		cout << ans << "\n";
	}
}

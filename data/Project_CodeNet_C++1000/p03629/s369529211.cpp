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
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

/*
 * a b c d ... z
 * aa ab ac ad ... az ba ... bz
 * a -> nxtpos(a, b, ... z)
 * For a subsequence of length k starting at this pos we need to have 2^k
 * or else we have an ans.
 * Now we can fix our starting points as first occurence of (a b c ... z)
 * And try forming a sequence of length k
 * store the nxt[i][26]
 * Do a dfs and have the path to the minimum failure where failure implies
 * not having a nxt[i][k] for some k
 *
 * */
const int N = 200 * 1000 + 5;
vector <int> dp(N, MOD), path(N, -1);
vector <bool> vis;
vector <vector<int>> nxt;
void dfs(int s) {
	vis[s] = true;
	for (int i = 0; i < 26; i++) {
		int g = nxt[s][i];
		if (g == -1) {
			dp[s] = 0;
			path[s] = g;
			return;
		}
		if (!vis[g])
			dfs(g);
		if (dp[g] + 1 < dp[s]) {
			path[s] = g;
			dp[s] = dp[g] + 1;
		}
	}
}
int main() {
	string s;
	cin >> s;
	int n = (int) s.size();
	vector <int> nxtPos(26, -1);
	nxt.assign(n, vector<int>(26));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			nxt[i][j] = nxtPos[j];
		}
		nxtPos[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
	    if (nxtPos[i] == -1) {
	        cout << char(i + 'a');
	        return 0;
	    }
	}
	vis.assign(n, false);
	for (int i = 0; i < n; i++) {
		if (!vis[i])
			dfs(i);
	}
	vector <int> seen(26, 0);
	vector <string> v;
	for (int i = 0; i < n; i++) {
		if (seen[s[i] - 'a']) continue;
		seen[s[i] - 'a'] = true;
		string t = "";
		int x = i, prev = -1;
		while(x != -1) {
			t += s[x];
			prev = x;
			x = path[x];
		}
		for (int j = 0; j < 26; j++) {
			if (nxt[prev][j] == -1) {
				t += char('a' + j);
				break;
			}
		}
		while (!v.empty() && (int) v.back().size() > (int) t.size()) {
			v.pop_back();
		}
		v.push_back(t);
	}
	sort(all(v));
	cout << v[0];
}

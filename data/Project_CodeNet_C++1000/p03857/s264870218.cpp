#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm> 
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define y1 abcde
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 2e5 + 15;
int n, k[2], ans[N];
vector <int> g[2][N];
int sz[N], p[N];
bool used[N];
int q[N], ql, qr;
int cnt[N];

int find(int v) {
	if(v == p[v])
		return v;
	return p[v] = find(p[v]);
}

void unio(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != b) {
		if(sz[a] < sz[b])
			swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
	}
}

main() {
	for(int i = 0; i < N; ++i)
		sz[i] = 1, p[i] = i;
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n >> k[0] >> k[1];
	for(int j = 0; j < 2; ++j)
		for(int i = 0; i < k[j]; ++i) {
			int u, v;
			cin >> u >> v;
			g[j][u].pb(v);
			g[j][v].pb(u);
			if(j == 1)
				unio(u, v);
		}
	for(int i = 1; i <= n; ++i) {
		if(!used[i]) {
			used[i] = true;
			q[ql = qr = 0] = i;
			vector <int> comp = {};
			while(ql <= qr) {
				int v = q[ql++];
				comp.pb(v);
				++cnt[find(v)];
				for(int to : g[0][v])
					if(!used[to]) {
						used[to] = true;
						q[++qr] = to;
					}
			}
			for(int v : comp)
				ans[v] = cnt[find(v)];
			for(int v : comp) {
				cnt[find(v)] = 0;
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
    return 0;
}
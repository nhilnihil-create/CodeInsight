// #include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <fstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
// #include <unordered_map>
#include <set>
#include <utility>
#include <bitset>
#include <limits>
#include <climits>
using namespace std;

#ifdef DEBUG
#define NDEBUG
#include "cout11.h"
#endif
#undef NDEBUG
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;

#define sz(a)  int((a).size())
#define pb  push_back
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())


const ll INF = 1000000000000000000LL;// 1e18


template <typename T>
void dij1(int nV, vector<vector<pair<int,T>>>& adjacent, vector<T>& d, int start) {
	// nV: |V|
	d.assign(nV, INF);
	d[start] = 0;
	vector<int> prev(nV, -1);

	priority_queue<pair<T, int>> Q;
	Q.push(make_pair(0, start));

	vector<bool> visited(nV, false);

	while (!Q.empty()) {
		T du = -Q.top().first;
        int u = Q.top().second; Q.pop();
		if (visited[u]) continue;
		visited[u] = true;

		int c = adjacent[u].size();
		for (int i=0; i<c; ++i) {
			int v = adjacent[u][i].first;
			T distance = adjacent[u][i].second;
			T alt = du + distance;
			if (d[v] > alt) {
				d[v] = alt;
				prev[v] = u;
				Q.push(make_pair(-alt, v));
			}
		}
	}
}

int main() {
    int N; cin >> N;

    vector<vector<pair<int,ll>>> adj(N);
    rep(i, N-1) {
        int ai,bi; ll ci; cin >> ai >> bi >> ci;
        --ai; --bi;
        adj[ai].pb(make_pair(bi, ci));
        adj[bi].pb(make_pair(ai, ci));
    }
    int Q, K; cin >> Q >> K;
    --K;

    vector<ll> d(N, INF);
    dij1(N, adj, d, K);
    // cout << d << endl;

    rep(j, Q) {
        int xi,yi; cin >> xi >> yi;
        --xi; --yi;
        ll ans = d[xi] + d[yi];
        cout << ans << endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <functional>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cassert>

#ifdef DEBUG
#include "library/Utility/debug.cpp"
#else
#define debug(...)
#endif

#define rep(i,n) for(int i=0;i<(n);++i)
#define EL '\n'
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
using lnt = long long;
constexpr lnt INF = 2e18;
/*-*/

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	std::vector<std::vector<int> > g(n);
	rep(i,n-1) {
		int x,y;
		std::cin >> x >> y;
		x--;y--;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	if(n==2) {
		if(a[0]==a[1]) print("YES");
		else print("NO");
		return 0;
	}
	// take root to be a non leaf node
	auto dfs = [&] (auto f, int i, int par) -> int {
		if(g[i].size()==1) {
			return a[i];
		}
		int flow = 2*a[i];
		for(auto to:g[i]) {
			if(to==par) continue;
			int ret = f(f,to,i);
			if(ret==-1) return -1;
			if(2*a[i]-ret<ret) return -1;
			flow-=ret;
		}
		debug(flow);
		if(2*a[i]-flow<flow) return -1;
		if(flow<0) return -1;
		return flow;
	};
	int root=-1;
	rep(i,n) if(g[i].size()!=1) root=i;
	debug(root);
	int x = dfs(dfs,root,-1);
	debug(x);
	if(x==0) print("YES");
	else print("NO");
}

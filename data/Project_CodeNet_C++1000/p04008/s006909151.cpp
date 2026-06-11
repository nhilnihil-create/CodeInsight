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
#include <limits>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <random>

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
struct FIO{FIO(){std::cin.tie(0);std::ios_base::sync_with_stdio(0);}}fIO;
/*-*/

int main() {
	int n,k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	rep(i,n) a[i]--;
	int count=0;
	if(a[0]!=0) count++;
	std::vector<std::vector<int> > g(n);
	rep(i,n) {
		if(i==0) continue;
		g[a[i]].emplace_back(i);
	}
	auto dfs = [&](auto f, int i, int par) -> int {
		int max=0;
		for(auto to:g[i]) {
			max=std::max(max,f(f,to,i));
		}
		if(par!=0&&max+1==k) {
			count++;
			return 0;
		}
		return max+1;
	};
	dfs(dfs,0,0);
	print(count);
}

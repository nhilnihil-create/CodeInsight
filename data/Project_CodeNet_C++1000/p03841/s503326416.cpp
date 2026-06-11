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

template <typename T>
std::vector<int> sort_indexes(const std::vector<T> &v) {
  std::vector<int> idx(v.size());
  std::iota(idx.begin(), idx.end(), 0);
  std::sort(idx.begin(), idx.end(), [&v](int i1, int i2) {return v[i1] < v[i2];});
  return idx;
}


int main() {
	lnt n;
	std::cin >> n;
	std::vector<lnt> a(n);
	rep(i,n) std::cin >> a[i];
	rep(i,n) a[i]--;
	std::vector<lnt> ans(n*n,-1);
	auto idx = sort_indexes(a);
	rep(i,n) {
		if(ans[a[i]]!=-1) {
			print("No");
			return 0;
		}
		ans[a[i]]=i;
	}
	{
		lnt j=0;
		for(lnt i:idx) {
			lnt cnt = i;
			for(;cnt>0&&j<a[i];j++) {
				if(ans[j]!=-1) continue;
				ans[j]=i;
				cnt--;
			}
			if(cnt>0) {
				print("No");
				return 0;
			}
		}
		for(lnt i:idx) {
			lnt cnt = n-i-1;
			while(j<n*n&&ans[j]!=-1) j++;
			if(j<a[i]) {
				print("No");
				return 0;
			}
			for(;cnt>0&&j<n*n;j++) {
				if(ans[j]!=-1) continue;
				ans[j]=i;
				cnt--;
			}
			if(cnt>0) {
				print("No");
				return 0;
			}
		}
	}
	print("Yes");
	rep(i,n*n) std::cout << ans[i]+1 << ' ';
	std::cout << EL;
}

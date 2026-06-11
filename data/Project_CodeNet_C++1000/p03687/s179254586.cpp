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

int main() {
	std::string s;
	std::cin >> s;
	lnt min=INF;
	for(char c: s) {
		std::string t=s;
		std::string r;
		lnt cnt=0;
		while(true) {
			debug(r,t);
			bool allc=true;
			for(auto cc:t) if(cc!=c) allc=false;
			if(allc) break;
			r="";
			rep(i,t.size()-1) {
				if(t[i]==c||t[i+1]==c) r+=c;
				else r+='.';
			}
			std::swap(r,t);
			cnt++;
		}
		min=std::min(min,cnt);
	}
	print(min);
}

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
struct FIO{FIO(){std::cin.tie(0);std::cout.tie(0);std::ios_base::sync_with_stdio(0);std::cout<<std::fixed<<std::setprecision(15);}}fIO;
/*-*/

int main() {
	lnt n,k;
	std::cin >> n >> k;
	std::vector<lnt> a(n);
	rep(i,n) std::cin >> a[i];
	lnt g=a[0];
	rep(i,n) g=std::gcd(g,a[i]);
	if(k%g==0 && k<=*std::max_element(all(a))) print("POSSIBLE");
	else print("IMPOSSIBLE");
}

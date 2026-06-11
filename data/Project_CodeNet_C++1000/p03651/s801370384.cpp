#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 998244353;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef unsigned long long ULL;
//typedef boost::multiprecision::cpp_int bigint;

//最大公約数
//O(log max(a,b))
template<class T>
T GCD(T a, T b) {
	if (b == 0)return a;
	return GCD(b, (T)(a % b));
}

int main() {
	std::ios::sync_with_stdio(false);
	LL N, K;
	cin >> N >> K;
	LL G;
	cin >> G;
	LL M = G;
	if (G == K) {
		cout << "POSSIBLE" << "\n";
		return 0;
	}
	for (LL n = 1; n < N; n++) {
		LL a;
		cin >> a;
		G = GCD(a, G);
		M = max(a, M);
		if (a == K) {
			cout << "POSSIBLE" << "\n";
			return 0;
		}
	}
	if (K % G == 0 && K <= M)cout << "POSSIBLE" << "\n";
	else cout << "IMPOSSIBLE" << "\n";
	return 0;
}

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
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef unsigned long long ULL;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	LL N, K;
	cin >> N >> K;
	VLL A(N);
	for (LL n = 0; n < N; n++)cin >> A[n];
	LL ans = 1e15;
	for (LL code = 0; code < ((LL)1 << N); code++) {
		VLL AA(A);
		LL color = 0;
		LL temp = 0;
		LL prev = 0;
		for (LL n = 0; n < N; n++) {
			if (code & ((LL)1 << n)) {
				if (prev >= AA[n]) {
					temp += (prev + 1) - AA[n];
					AA[n] = prev + 1;
				}
				color++;
			}
			prev = max(prev, AA[n]);
		}
		if (color < K)continue;
		ans = min(ans, temp);
	}
	cout << ans << "\n";
	return 0;
}
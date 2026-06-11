#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <vector>
#include <queue>
#include <unordered_map> 
#include <iomanip>
#include <random>
#include <future>
#include <thread>
#include <utility>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define INF (INT_MAX/3)
#define INF_L (LLONG_MAX/3)
#define PSB push_back
#define PN 1000000007
typedef long long LL;
#define int long long


// booooooooooooost
// #include <boost/multiprecision/cpp_int.hpp>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// namespace mp = boost::multiprecision;	//多倍長整数(mp::cpp_int), 多倍長小数(mp::cpp_dec_float_100)


signed main() {

	int K;
	cin >> K;

	int N = 50;
	int modK = K % N, divK = K / N;
	vector<int> ans(N, N - 2 + divK); ++ans.back();
	for (int i = 0; i < modK; ++i) {
		sort(ans.begin(), ans.end());
		ans[0] += N;
		for (int j = 1; j < N; ++j) {
			--ans[j];
		}
	}

	cout << N << endl;
	for (int i = 0; i < N; ++i) {
		cout << ans[i];
		if (i != N - 1) cout << " ";
	}
	cout << endl;

	return 0;
}
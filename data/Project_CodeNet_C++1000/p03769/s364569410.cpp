#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<array>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cassert>
#include<functional>
#include<random>
#include<complex>
#include<bitset>
#include<chrono>
//#include<boost/multiprecision/cpp_int.hpp>
#define int int64_t
#define uint uint64_t
#define REP(i, a, b) for (int64_t i = (int64_t)(a); i < (int64_t)(b); i++)
#define rep(i, a) REP(i, 0, a)
#define SZ(X) ((int64_t)((X).size()))
#define ITR(x, a) for (auto x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define HAS(a, x) (a.find(x) != a.end())
#define Min(x) *min_element(ALL(x))
#define Max(x) *max_element(ALL(x))
#define Unique(L) (L.erase(unique(ALL(L)), L.end()))
#define intmax (std::numeric_limits<int64_t>::max() / 4)
#define doublemax (std::numeric_limits<double>::max() / 4)
using namespace std;
//typedef boost::multiprecision::cpp_int bigint;
const double EPS = 1e-9;
const double PI = acos(-1.0);



vector<int> construct(int N) {
	int n;
	vector<int> p;
	for (n = 40; n>0; n--) {
		if (N >= (1LL << n) - 1)break;
	}
	for (int i = 1; i <= n; i++)
		p.push_back(i);
	N -= (1LL << n) - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (N<1LL << i)continue;
		n++;
		p.insert(p.begin() + i, n);
		N -= 1LL << i;
	}
	return p;
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	auto p = construct(N);
	int S = p.size();
	rep(i, S)p.push_back(i + 1);

	cout << p.size() << endl;
	rep(i, p.size()) {
		if (i)cout << " ";
		cout << p[i];
	}

	return 0;
}
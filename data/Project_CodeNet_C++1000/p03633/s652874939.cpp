#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

template<class T>
map<T, int> prime_factorization(T n) {
	map<T, int> ret;

	for (long long i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}

	if (n != 1)ret[n] = 1;
	return ret;
}


int main() {
	int N;
	cin >> N;

	map<long long, long long> vec;
	for (int i = 0; i < N; ++i) {
		long long a;
		cin >> a;

		vec[a] = 1;
	}
	

	map<long long, int> mp;

	for (auto x : vec) {
		if (N == 1 || 5e17 < x.first) {
			cout << x.first << endl;
			return 0;
		}
		map<long long, int> mp2;
		
		mp2 = prime_factorization(x.first);
		for (auto y : mp2) {
			mp[y.first] = max(mp[y.first], y.second);
		}
	}

	long long ans = 1;
	for (auto x : mp) {
		long long y = x.second;
		long long yP = 1;
		for (int i = 0; i < x.second; ++i) yP *= x.first;
		ans = ans * yP;
	}

	cout << ans << endl;
	return 0;
}

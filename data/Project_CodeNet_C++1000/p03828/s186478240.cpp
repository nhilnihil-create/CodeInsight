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
void prime_factorization(T n, map<T, int> &ret) {
	for (long long i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}

	if (n != 1)ret[n] += 1;
}



int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	map<long long, int> mp;
	for (long long i = 1; i <= N; ++i) {
		prime_factorization(i, mp);
	}
	
	long long ans = 1;
	for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
		long long buf = iter->second;
		ans = (ans * (buf + 1)) % MOD;
	}

	cout << ans << endl;
	return 0;
}
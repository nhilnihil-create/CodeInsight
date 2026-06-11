#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, long long>> prime(long long N) {

	vector<pair<long long, long long>> res;

	for (long long a = 2; a * a <= N; a++) {
		if (N%a != 0) continue;
		int ex = 0;
		while (N % a == 0) {
			ex++;
			N /= a;
		}
		res.push_back({ a,ex });
	}
	if (N != 1) res.push_back({ N,1 });
	return res;
}

int main(void) {
	
	long long N;

	cin >> N;
	vector<long long> e(N+1,0);
	
	for(long long i=1;i<=N;i++){
		const auto& res = prime(i);
		for (auto p : res)
			e[p.first] += p.second;
	}

	long long c = 1;

	for (long long i = 0; i < N + 1; i++) {
		c *= e[i] + 1;
		c %= 1000000007;
	}
		
	cout << c;

}
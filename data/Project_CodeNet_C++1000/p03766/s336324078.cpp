#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9+7;
int64_t N;

vector<int64_t> F, G;


int64_t g(int);

int64_t f(int n) {
	if (n == 1)
		return N;
	if (n <= 0)
		return 1;
	if (F[n] != -1)
		return F[n];
	int64_t ways = f(n-1);
	ways += (N-1);
	ways %= MOD;
	if (n >= 2)
		ways += (N-1)*(N-2);
	ways %= MOD;
	ways += g(n-3);
	ways %= MOD;
	ways += abs(n-1-N);
	ways %= MOD;
	// for (int num = 2; num <= N; ++num) {
	// 	ways += f(n-1-num);
	// 	ways %= MOD;
	// }
	return F[n] = ways;
}

int64_t g(int n) {
	if (n < 0)
		return 0;
	if (G[n] != -1)
		return G[n];
	return G[n] = (f(n)+g(n-1))%MOD;
}


int main() {
	cin >> N;
	F.assign(N+1, -1);
	G = F;
	cout << f(N) << endl;
}
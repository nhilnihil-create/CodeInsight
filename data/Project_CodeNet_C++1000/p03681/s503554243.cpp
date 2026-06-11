#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long f[100100];
void fanc() {
	f[0] = f[1] = 1;
	for (int i = 2; i < 100100; i++)
	{
		f[i] = f[i-1] * i % MOD;
	}
}

int main() {
	int N, M; cin >> N >> M;
	fanc();
	if(abs(N - M) >= 2) cout << "0" << endl;
	else if(abs(N - M) == 1) {
		long long res = f[N] * f[M] % MOD;
		cout << res << endl;
	}
	else {
		long long res = (f[N] * f[M] % MOD) * 2 % MOD;
		cout << res << endl;
	}
	return 0;
}

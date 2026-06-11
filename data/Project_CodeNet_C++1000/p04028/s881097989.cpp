#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, M;
string S;
ll DP[5001][5001];

ll pw(ll x, int y) {
	ll a = 1;
	while (y) {
		if (y & 1) {
			a = a*x%mod;
		}
		x = x*x%mod;
		y /= 2;
	}
	return a;
}

ll modinv(ll x) {
	return pw(x, mod - 2);
}

int main() {
	cin >> N >> S;
	M = S.size();
	DP[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		DP[i + 1][0] = DP[i][0];
		for (int j = 0; j < N; ++j) {
			DP[i + 1][j + 1] = DP[i][j] * 2 % mod;
			DP[i + 1][j - 1] = (DP[i + 1][j - 1] + DP[i][j]) % mod;
		}
	}
	cout << DP[N][M] * modinv(pw(2, M)) % mod << endl;
}
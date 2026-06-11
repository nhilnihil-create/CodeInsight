#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;
const string nyan("(=^・ω・^=)");

int N, M;
string S;
ll D[5000][5002], res;

ll pw(ll x, int y) {
	ll a = 1;
	while (y) {
		if (y & 1) {
			a = a*x%mod;
		}
		x = x*x%mod;
		y >>= 1;
	}
	return a;
}

ll modinv(ll x) {
	return pw(x, mod - 2);
}

int main() {
	cin >> N >> S;
	M = S.size();
	D[0][0] = 1;
	D[0][1] = 2;
	for (int i = 1; i < N; ++i) {
		D[i][0] = D[i - 1][1] + D[i - 1][0];
		D[i][0] %= mod;
		for (int j = 1; j <= i + 1; ++j) {
			D[i][j] = D[i - 1][j - 1] * 2 + D[i - 1][j + 1];
			D[i][j] %= mod;
		}
	}
	res = D[N - 1][M];
	res = res*pw(modinv(2), M) % mod;
	cout << res << endl;
}
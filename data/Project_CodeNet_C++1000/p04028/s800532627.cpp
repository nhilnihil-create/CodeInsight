//間違えて打った文字を打ち消すことを考えると難しい（状態を減らせない）.
//間違えて打った文字を打ち消さないとどうなるか。
//とりあえずN回押して, |S|文字になったとする.
//当然文字列Sと一致しないバイナリ列ができうる。バイナリ列は2^|S|通りできうるが、
//それらは等確率でできるので、文字列Sを作る方法の個数は、「N回押して|S|文字にする方法の個数」
//を2^|S|で割ったものと等しい。よって、これをDPで求めればいいことになった。間に合う。
#include <iostream>
#include <string>
#include <algorithm>
#define int long long
using namespace std;

int mod = 1000000007;
int n, m;
string s;
int dp[5001][5001];	//dp[i][j] = i回打った直後にj文字存在する打ち方の個数

int powmod(int a, int n, int mod) {
	if (n == 0) return 1;
	if (n % 2) return (a * powmod(a, n - 1, mod)) % mod;
	return powmod((a * a) % mod, n / 2, mod);
}

signed main()
{
	int i, j;
	
	cin >> n >> s;
	m = s.length();
	
	dp[0][0] = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			dp[i + 1][j + 1] += dp[i][j] * 2;
			dp[i + 1][j + 1] %= mod;
			dp[i + 1][max(0LL, j - 1)] += dp[i][j];
			dp[i + 1][max(0LL, j - 1)] %= mod;
		}
	}
	
	int inv = powmod(powmod(2, mod - 2, mod), m, mod);
	int ans = (dp[n][m] * inv) % mod;
	cout << ans << endl;
	return 0;
}
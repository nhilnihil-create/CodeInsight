#include <bits/stdc++.h>
#pragma warning (disable:4996)

using namespace std;
using ll = long long;
using LL = ll;
using ull = unsigned long long;
using uLL = ull;
#define clean_0(A) memset((A),0,sizeof(A))
#define clean_1(A) memset((A),-1,sizeof(A))
#define For(i,a,b) for(int (i)=(a);(i)<=b;++(i))
#define Max_(a,b) ((a)>=(b)?(a):(b))
#define Min_(a,b) ((a)<=(b)?(a):(b))
template<typename T>
inline T Max(T a, T b) { return a >= b ? a : b; }
template<typename T>
inline T Min(T a, T b) { return a <= b ? a : b; }

constexpr int INF = 0x7F7F7F7F;
constexpr double eps = 1e-9;

constexpr ll mod1 = 197;
constexpr ll mod2 = 19260817;
constexpr ll mod3 = ll(1e8) + 7;
constexpr ll mod4 = ll(1e9) + 7;;
constexpr ll mod5 = 998244353;
constexpr int mod = mod4;

constexpr int maxn = int(3e5) + 1;
constexpr int MAXN = maxn;
namespace io {

#define in(a) (a=read())
#define out(a) write(a)
#define outn(a) (out(a),putchar('\n'))

#define I_int  int
	inline I_int read() {
		I_int x = 0, f = 1; char c = getchar();
		while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
		while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
		return x * f;
	}
	template<typename T>
	bool scan_d(T& ret)
	{
#define p(x) ((x)>='0'&&(x)<='9')
		int c; int sgn;
		if (c = getchar(), c == EOF)return false;
		while (c != '-' && !p(c))c = getchar();
		sgn = (c == '-') ? -1 : 1;
		ret = (c == '-') ? 0 : c - '0';
		while (c = getchar(), p(c))ret = ret * 10 + c - '0';
		ret *= sgn;
		return true;
#undef p
	}
	char F[200];
	template<typename T>
	inline void write(T x) {
		if (x == 0) { putchar('0'); return; }
		auto tmp = x > 0 ? x : -x;
		if (x < 0) putchar('-');
		int cnt = 0;
		while (tmp > 0) {
			F[cnt++] = tmp % 10 + '0';
			tmp /= 10;
		}
		while (cnt > 0) putchar(F[--cnt]);
	}
	void read(char* s, int Arr[], size_t n)
	{
		for (size_t i = 0; i < n; ++i)Arr[i] = strtoll(s, &s, 10);
	}
#undef I_int

}
using namespace io;


template<typename T>
T exgcd(T a, T b, T& x, T& y)
{
	if (a == 0 && b == 0)return -1;
	if (b == 0) { x = 1, y = 0; return a; }
	T d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
//template<typename T>
//T inv(T a,T Mod=mod)
//{
//	T x, y;
//	return exgcd(a, Mod, x, y) == 1 ? (x % Mod + Mod) % Mod : -1;
//}
template<typename T>
constexpr T _gcd(T a, T b)
{
	return b ? _gcd(b, a % b) : a;
}
template<typename T>
constexpr T combinator(T n, T m, T Mod = mod - 1)
{
	m = min(m, n - m);
	T ret = 1;
	for (T i = 1; i <= m; ++i)
	{
		ret = ret * (n - m + i) / i % Mod;
	}
	return ret;
}
template<typename T>
constexpr T poww(T a, T b, T Mod = mod)
{
	T ret = 1;
	a %= Mod;
	b %= Mod - 1;
	if (b < 0)b += Mod - 1;
	while (b)
	{
		if (b & 1)ret = ret * a % Mod;
		a = a * a % Mod;
		b >>= 1;
	}
	return ret;
}

struct Combinator
{
	static constexpr int Mod = ::mod;
	static constexpr int Maxn = 1;//::maxn;
	int dp[Maxn][Maxn];//this is C(n,m)%(mod-1)
	constexpr Combinator() :dp()
	{
		for (int i = 0; i < Maxn; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j == 0) dp[i][j] = 1;
				else if (i == j) dp[i][j] = 1;
				else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % (Mod - 1);
			}
		}
	}
};
ll Fact[maxn], Inv[maxn];
//void Init(int n)
//{
//	Fact[0] = 1;
//	for (int i = 1; i <= n; i++)
//		Fact[i] = Fact[i - 1] * i % mod;
//	Inv[0] = 1;
//	Inv[n] = poww(Fact[n], mod - 2LL);
//	for (int i = n - 1; i > 0; i--)
//		Inv[i] = Inv[i + 1] * (i + 1LL) % mod;
//}
//ll C(int a, int b) {
//	if (a < 0 || b < 0)return 1;
//	return F[a] * Inv[b] % mod * Inv[a - b] % mod;
//}
//int main()
//{
//	Init(2.1e5);
//	int a, b, h, w;
//	while (cin >> h>>w>>a>>b)
//	{
//		ll ans = C(h + w - 2, h - 1);
//		for (ll i = 1; i <= b; i++) {
//			ans -= C(h - a + i - 2, h - a - 1) * C(a - 1 + w - i, a - 1) % mod;
//			ans = (ans % mod + mod) % mod;
//		}
//		printf("%lld", ans);
//	}
//}
int H, W, A, B;
const ll Maxn = maxn;
const int Mod = mod;
//ll Fact[Maxn + 10], Inv[Maxn + 10];
int N;
void Init(int N)
{
	Fact[0] = 1;
	for (int i = 1; i <= N; i++)
		Fact[i] = Fact[i - 1] * i % Mod;
	Inv[0] = 1;
	Inv[N] = poww(Fact[N], Mod - 2LL);
	for (int i = N - 1; i > 0; i--)
		Inv[i] = Inv[i + 1] * (i + 1) % Mod;
}
ll C(int a, int b) {
	if (a < 0 || b < 0)return 1;
	return Fact[a] * Inv[b] % Mod * Inv[a - b] % Mod;
}
int main() {
	scanf("%d %d %d %d", &H, &W, &A, &B);
	N = H + W - 2;
	Init(H+W-2);
	ll ans = C(H + W - 2, H - 1);
	for (ll i = 1; i <= B; i++) {
		ans -= C(H - A + i - 2, H - A - 1) * C(A - 1 + W - i, A - 1) % Mod;
		ans = (ans % Mod + Mod) % Mod;
	}
	printf("%lld", ans);
}
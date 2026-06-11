/*
把白球当成左括号，把每个颜色的球第一次出现当成右括号
那么方案合法当且仅当括号匹配，直接dp即可 
*/
#include <cstdio>

using namespace std;
const int MOD(1000000000 + 7);
const int Max_N(2050);
const int Max_K(2050);

constexpr int Mult(int a, int b)
{
	return a * 1LL * b % MOD;
}

constexpr int Add(int a, int b)
{
	return a + b >= MOD ? a + b - MOD : a + b;
}

void exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
		x = 1, y = 0;
	else
		exgcd(b, a % b, y, x), y -= x * (a / b);
}

inline int inverse(int a)
{
	int invx, invy;
	exgcd(a, MOD, invx, invy);
	return (invx % MOD + MOD) % MOD;
}

int N, K, Fac[Max_N * Max_K], Inv[Max_N * Max_K], F[Max_N][Max_N];
//F[i][j]表示已经用了i个白球，有j个白球没有用的方案数 

inline void upd(int &a, int b)
{
	a = Add(a, b);
}

inline int C(int n, int m)
{
	return Mult(Fac[n], Mult(Inv[m], Inv[n - m]));
}

int main()
{
	scanf("%d%d", &N, &K);
	if (K == 1)
	{
		printf("1");
		return 0;
	}
	Fac[0] = 1;
	for (int i = 1;i <= N * K;++i)
		Fac[i] = Mult(Fac[i - 1], i);
	Inv[N * K] = inverse(Fac[N * K]);
	for (int i = N * K - 1;i >= 0;--i)
		Inv[i] = Mult(Inv[i + 1], i + 1);
	F[0][0] = 1;
	for (int i = 0;i <= N;++i)
		for (int j = 0;i + j <= N;++j)
		{
			//添加一个白球
			upd(F[i][j + 1], F[i][j]);
			if (j)
				upd(F[i + 1][j - 1], Mult(F[i][j], C((N - i - j) * K + j * (K - 1) - 1, K - 2)));
		}
	printf("%d", Mult(F[N][0], Fac[N]));
	return 0;
}
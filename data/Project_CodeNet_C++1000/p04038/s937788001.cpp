
#include <cstdio>

using namespace std;

const int Max_N(2050);
const int Max_V(2000 * 2000);
const int MOD(1000000000 + 7);
typedef long long int LL;

inline void update(int &a, const int &b)
{
	((a += b) >= MOD) ? (a -= MOD) : 0;
}

inline int Mult(const int &a, const int &b)
{
	return static_cast<int>(static_cast<LL>(a) * static_cast<LL>(b) % static_cast<LL>(MOD));
}

int N, K, F[Max_N][Max_N], Fac[Max_V + 5], Inv[Max_V + 5];
//每个颜色相当于放一个0然后在后面放K - 1个某种颜色 
//F[i][j]表示放了i个0，确定了j个某种颜色剩下K - 1个位置的方案数
//转移枚举当前位置放一个0，还是增加某种颜色的K - 1个位置（当前位置必须是这种颜色） 

void exgcd(const int &a, const int &b, int &x, int &y)
{
	if (b == 0)
		x = 1, y = 0;
	else
		exgcd(b, a % b, y, x), y -= x * (a / b);
}

inline int inverse(const int &a)
{
	int invx, invy;
	exgcd(a, MOD, invx, invy);
	return (invx % MOD + MOD) % MOD;
}

inline int C(const int &n, const int &m)
{
	return Mult(Mult(Fac[n], Inv[n - m]), Inv[m]);
}

int main()
{
	Fac[0] = 1;
	for (int i = 1;i <= Max_V;++i)
		Fac[i] = Mult(Fac[i - 1], i);
	Inv[Max_V] = inverse(Fac[Max_V]);
	for (int i = Max_V - 1;i >= 0;--i)
		Inv[i] = Mult(Inv[i + 1], i + 1);
	scanf("%d%d", &N, &K);
	if (K == 1)
	{
		printf("1");
		return 0;
	}
	F[1][0] = 1;
	for (int i = 1;i <= N;++i)
		for (int j = 0;j <= i;++j)
		{
			update(F[i + 1][j], F[i][j]);
			if (j + 1 <= i)
				update(F[i][j + 1], Mult(Mult(F[i][j], N - j), C((N - i) + (N - j) * (K - 1) - 1, K - 2)));
		}
	printf("%d", F[N][N]);
	return 0;
}
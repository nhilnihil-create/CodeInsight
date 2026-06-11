
#include <cstdio>

using namespace std;

//设F[i]表示长度为i的序列的答案 
//如果A[1] = 1，那么它对于后面的元素没有影响，这一部分数量就是F[i - 1]
//如果A[1] > 1且A[2] > 1，那么由于A[1] > 1，所以A[3] = A[2] > 1，以此类推可以得到A[2] = A[3] = ...，这一部分答案为(N - 1)^2
//如果A[1] > 1且A[2] = 1，那么A[2] = A[3] = ... = A[1 + A[1]] = 1。如果1 + A[1] >= i，那么后面就全部是1。否则答案为F[i - 1 - A[1]] 

const int Max_N(1000050);
const int MOD(1000000000 + 7);
typedef long long int LL;

inline void update(int &a, const int &b)
{
	((a += b) >= MOD) ? (a -= MOD) : 0;
}

inline int Mult(const int &a, const int &b)
{
	return (a * 1LL) * b % MOD;
}

int N, F[Max_N], S[Max_N];

int main()
{
	scanf("%d", &N);
	S[1] = F[1] = N;
	for (int i = 2;i <= N;++i)
	{
		update(F[i], F[i - 1]);
		update(F[i], Mult(N - 1, N - 1));
		update(F[i], N - i + 2 - (i - 1 == 1));
		if (i >= 3)
			update(F[i], S[i - 3]);
		S[i] = (S[i - 1] + F[i]) % MOD;
	}
	printf("%d", F[N]);
	return 0;
}
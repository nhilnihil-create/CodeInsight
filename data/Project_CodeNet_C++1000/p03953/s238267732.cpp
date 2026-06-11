/*
设pos(x)表示编号为x的兔子的坐标
假设某一轮跳跃是兔子aj，其选择的是x，有pos'(aj) = 2 * pos(x) - pos(aj)
E(pos'(aj)) = 2 * E(pos(x)) - E(pos(aj)) = 2 * (E(pos(aj - 1)) + E(pos(aj + 1))) / 2 - E(pos(aj)) = E(pos(aj - 1)) + E(pos(aj + 1)) - E(pos(aj))
注意到E(pos'(aj)) - E(pos(aj - 1)) = E(pos(aj + 1)) - E(pos(aj)), E(pos(aj + 1)) - E(pos'(aj)) = E(pos(aj)) - E(pos(aj - 1))
故该操作等价于交换了两个差分值。直接做置换快速幂即可 
*/

#include <cstdio>
#include <algorithm>

using namespace std;

template<typename Type>
void Get_Val(Type &Ret)
{
	Ret = 0;
	char ch;
	bool Neg(false);
	while (ch = getchar(), (ch > '9' || ch < '0') && ch != '-')
		;
	if (ch == '-')
	{
		Neg = true;
		while (ch = getchar(), ch > '9' || ch < '0')
			;
	}
	do
	{
		(Ret *= 10) += ch - '0';
	}
	while (ch = getchar(), ch >= '0' && ch <= '9');
	Ret = (Neg ? -Ret : Ret);
}

const int Max_N(100050);
const int Max_M(100050);
typedef long long int LL;

int N, X[Max_N], M, A[Max_M], Now[Max_N], P[Max_N];
LL K;
int Tot, All[Max_N];
bool done[Max_N];

void dfs(const int &u)
{
	if (done[u])
		return;
	done[u] = true;
	All[Tot++] = u;
	dfs(P[u]);
}

int main()
{
	Get_Val(N);
	for (int i = 1;i <= N;++i)
		Get_Val(X[i]), Now[i] = i;
	Get_Val(M), Get_Val(K);
	for (int i = 1;i <= M;++i)
		Get_Val(A[i]), swap(Now[A[i]], Now[A[i] + 1]);
	for (int i = 1;i <= N;++i)
		P[Now[i]] = i;
	for (int i = 1;i <= N;++i)
		if (!done[i])
		{
			Tot = 0, dfs(i);
			for (int i = 0;i <= Tot - 1;++i)
				P[All[i]] = All[(i + K) % Tot];
		}
	for (int i = 1;i <= N;++i)
		Now[P[i]] = i;
	LL cha(0LL);
	for (int i = 1;i <= N;++i)
		printf("%lld\n", cha += X[Now[i]] - X[Now[i] - 1]);
	return 0;
}
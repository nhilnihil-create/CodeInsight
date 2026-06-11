
#include <cstdio>

using namespace std;

void Get_Val(int &Ret)
{
	Ret = 0;
	char ch;
	while (ch = getchar(), ch > '9' || ch < '0')
		;
	do
	{
		(Ret *= 10) += ch - '0'; 
	}
	while (ch = getchar(), ch >= '0' && ch <= '9');
}

const int Max_N(100050);

int N, Total, Head[Max_N], To[Max_N << 1], Next[Max_N << 1];

inline void Add_Edge(const int &s, const int &t)
{
	++Total, To[Total] = t, Next[Total] = Head[s], Head[s] = Total;
}

void init()
{
	Get_Val(N);
	for (int i = 1, u, v;i != N;++i)
		Get_Val(u), Get_Val(v), Add_Edge(u, v), Add_Edge(v, u);
}

int SG[Max_N];
void dp(const int &u, const int &fa)
{
	for (int i = Head[u], v;i;i = Next[i])
		if ((v = To[i]) != fa)
			dp(v, u), SG[u] ^= (SG[v] + 1);
}

int main()
{

	init();
	dp(1, -1);
	if (SG[1])
		printf("Alice");
	else
		printf("Bob");
	return 0;
}
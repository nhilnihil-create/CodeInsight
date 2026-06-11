
#include <cstdio>
#include <vector>

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

const int Max_M(100050);

int N, M, BIT[Max_M];
vector< pair<int, int> > V[Max_M];

inline int lowbit(const int &x)
{
	return x & -x;
}

void insert(int i, const int &v)
{
	while (i <= M)
		BIT[i] += v, i += lowbit(i);
}

int query(int i)
{
	int Ret(0);
	while (i)
		Ret += BIT[i], i -= lowbit(i);
	return Ret;
}

inline void Add(const int &l, const int &r)
{
	insert(l, +1), insert(r + 1, -1);
}

int main()
{
	int Ans(0), Tmp;
	Get_Val(N), Get_Val(M);
	for (int i = 1, l, r;i <= N;++i)
		Get_Val(l), Get_Val(r), V[r - l + 1].push_back(make_pair(l, r)), ++Ans;
	for (int i = 1;i <= M;++i)
	{
		Tmp = Ans;
		for (int j = i;j <= M;j += i)
			Tmp += query(j);
		for (int j = 0;j != V[i].size();++j)
		{
			--Ans;
			Add(V[i][j].first, V[i][j].second);
		}
		printf("%d\n", Tmp);
	}
	return 0;
}

#include <map>
#include <cstdio>

using namespace std;
const int Max_N(505);

int N, Ans[Max_N * Max_N];
map<int, int> X, S;

int main()
{
	scanf("%d", &N);
	for (int i = 1, x;i <= N;++i)
	{
		scanf("%d", &x);
		if (X.count(x))
		{
			puts("No");
			return 0;
		}
		X[x] = i;
	}
	for (map<int, int>::iterator it = X.begin();it != X.end();++it)
	{
		int x, i, cnt = 1;
		Ans[x = it -> first] = i = it -> second;
		for (int j = 1;j < x && cnt < i;++j)
			if (!Ans[j])
				Ans[j] = i, ++cnt;
		if (cnt < i)
		{
			puts("No");
			return 0;
		}
	}
	for (int i = 1;i <= N * N;++i)
	{
		if (!Ans[i])
		{
			if (S.empty())
			{
				puts("No");
				return 0;
			}
			Ans[i] = S.begin() -> first;
			if ((--S[S.begin() -> first]) == 0)
				S.erase(S.begin() -> first);
		}
		if (X.count(i) && X[i] < N)
			S[X[i]] = N - X[i];
	}
	puts("Yes");
	for (int i = 1;i <= N * N;++i)
		printf("%d ", Ans[i]);
	return 0;
}
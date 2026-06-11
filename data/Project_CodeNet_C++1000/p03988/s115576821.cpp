
#include <cstdio>
#include <algorithm>

using namespace std;
const int Max_N(105);

int N, Cnt[Max_N];

int main()
{
	scanf("%d", &N);
	for (int i = 1, a;i <= N;++i)
		scanf("%d", &a), ++Cnt[a], Cnt[0] = max(Cnt[0], a);
	if ((Cnt[0] & 1) == 0)
	{
		for (int i = 0;i <= Cnt[0] / 2 - 1;++i)
			if (Cnt[Cnt[0] - i] < 2)
			{
				puts("Impossible");
				return 0;
			}
		if (Cnt[Cnt[0] - Cnt[0] / 2] != 1)
		{
			puts("Impossible");
			return 0;
		}
		for (int i = Cnt[0] / 2 + 1;i <= Cnt[0] - 1;++i)
			if (Cnt[Cnt[0] - i])
			{
				puts("Impossible");
				return 0;
			}
	}
	else
	{
		for (int i = 0;i <= Cnt[0] / 2 - 1;++i)
			if (Cnt[Cnt[0] - i] < 2)
			{
				puts("Impossible");
				return 0;
			}
		if (Cnt[Cnt[0] - Cnt[0] / 2] != 2)
		{
			puts("Impossible");
			return 0;
		}
		for (int i = Cnt[0] / 2 + 1;i <= Cnt[0] - 1;++i)
			if (Cnt[Cnt[0] - i])
			{
				puts("Impossible");
				return 0;
			}
	}
	puts("Possible");
	return 0;
}
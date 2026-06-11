#include <cstdio>

typedef long long ll;
char qu[10];
int main()
{
	int len = 1;
	for (ll i = 10; len <= 10; i *= 10)
	{
		printf("? %lld\n", i );
		fflush(stdout);
		scanf("%s", qu);
		if (qu[0] == 'N') break;
		++len;
	}
//	printf("%d\n", len );
	if (len == 11)
	{
		for (ll i = 9; i < 10000000000ll; i = i * 10 + 9)
		{
			printf("? %lld\n", i );
			fflush(stdout);
			scanf("%s", qu);
			if (qu[0] == 'Y') return !printf("! %lld\n", (i + 1) / 10 );
		}
	}
	int ans = 0, pw = 1;
	for (int i = 1; i < len; ++i) pw *= 10;
	for (int i = 1; i < len; ++i)
	{
		int left = 0, right = 10;
		while (left < right)
		{
			int mid = left + right >> 1;
			printf("? %d\n", ans * 10 + mid );
			fflush(stdout);
			scanf("%s", qu);
			if (qu[0] == 'Y') left = mid + 1;
			else right = mid;
		}
		ans = ans * 10 + left - 1;
	}
	int left = 0, right = 10;
	while (left < right)
	{
		int mid = left + right >> 1;
		printf("? %lld\n", (ans * 10 + mid) * 10ll );
		fflush(stdout);
		scanf("%s", qu);
		if (qu[0] == 'N') left = mid + 1;
		else right = mid;
	}
	ans = ans * 10 + left;
	printf("! %d\n", ans );
	return 0;
}
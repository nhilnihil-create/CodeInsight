#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 1e5 + 100;
char s[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	scanf("%s", s);

	int sum = 0, fo = 0;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'c')
		{
			printf("No\n");
			continue;
		}
		if (s[i] == 'a')
		{
			if (sum < a + b)
			{
				sum++;
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
			continue;
		}
		if (s[i] == 'b')
		{
			if (sum < a + b && fo < b)
			{
				sum++;
				fo++;
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
			continue;
		}
		throw;
	}

	return 0;
}


#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const double pi = acos(-1);
const int maxn = 2e6 + 10;
const double eps = 1e-8;
const ll mod = 1e9 + 7;
const ull base = 131;
const ull mod1 = 1e9 + 9;
const ull mod2 = 1610612741;

char s[maxn];

int main()
{
	scanf("%s", s+1);
	int n = strlen(s+1);
	if (n == 2 && s[1] == s[2])
	{
		printf("%d %d\n", 1, 2);
		return 0;
	}
	for (int i = 2; i <= n-1; ++i)
	{
		if (s[i] == s[i+1])
		{
			printf("%d %d\n", i, i+1);
			return 0;
		}
		else if (s[i] == s[i-1])
		{
			printf("%d %d\n", i-1, i);
			return 0;
		}
		else if (s[i+1] == s[i-1])
		{
			printf("%d %d\n", i-1, i+1);
			return 0;
		}
	}
	printf("-1 -1\n");
	return 0;
}
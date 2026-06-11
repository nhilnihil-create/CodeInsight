#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 100010
#define ri register int

using namespace std;

int N;
int a[MAXN];

inline int read_int()
{
	register int ret = 0, f = 1; register char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {ret = (ret << 1) + (ret << 3) + int(c - 48); c = getchar();}
	return ret * f;
}

inline bool cmp(int x, int y) {return x > y;}

inline void init()
{
	N = read_int();
	for(ri i = 1; i <= N; i++)
		a[i] = read_int();
	sort(a + 1, a + N + 1, cmp);
}

inline void dp()
{
	for(ri i = 1; i <= N; i++)
	{
		if(i + 1 > a[i + 1])
		{
			ri j = i + 1, ans = 0;
			while(a[j] == i)
				ans ^= 1, j++;
			if((ans || ((a[i] - i) & 1)))
				puts("First");
			else
				puts("Second");
			return;
		}
	}
}

int main()
{
	init();
	dp();
	return 0;
}
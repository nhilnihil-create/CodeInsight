#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define MAXN 100005

int n;
int a[MAXN];

bool cmp (int a,int b){return a > b;}

int read ()
{
	int x = 0;char c = getchar();int f = 1;
	while (c < '0' || c > '9'){if (c == '-') f = -f;c = getchar();}
	while (c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + c - '0';c = getchar();}
	return x * f;
}

void write (int x)
{
	if (x < 0){x = -x;putchar ('-');}
	if (x > 9) write (x / 10);
	putchar (x % 10 + '0');
}

signed main()
{
	n = read ();
	for (Int i = 1;i <= n;++ i) a[i] = read ();
	sort (a + 1,a + n + 1,cmp);
	for (Int i = 1;i <= n;++ i)
		if (i + 1 > a[i + 1])
		{
			int j = 0;
			for (;a[i + j + 1] == i;++ j);
			if (((i - a[i]) & 1) || (j & 1)) puts ("First");
			else puts ("Second");
			return 0;
		}
	return 0;
}
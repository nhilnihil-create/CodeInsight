#include <cstdio>
#include <iostream>

using namespace std;
const int N = 200000;

int n, L;
int a[N], f[N][32];

int read(void)
{
	int s = 0, w = 0; char c = getchar();
	while (c < '0' || c > '9') w |= c == '-', c = getchar();
	while (c >= '0' && c <= '9') s = s*10+c-48, c = getchar();
	return w ? -s : s;
}

int main(void)
{
	n = read();
	for (int i=1;i<=n;++i)
		a[i] = read();
	L = read();
	for (int i=1,pos=2;i<=n;++i)
	{
		while (pos <= n && a[pos] - a[i] <= L) pos ++;
		f[i][0] = pos - 1;
	}
	a[n+1] = a[n] + 1;
	for (int i=1;i<=30;++i)
	    for (int j=1;j<=n;++j)
	        f[j][i] = f[f[j][i-1]][i-1];
	int m = read();
	while (m --)
	{
		int l = read(), r = read(), cnt = 0;
		if (l > r) swap(l,r);
		for (int i=30;~i;--i) 
		{
			if (f[l][i] >= r) continue;
			cnt += 1<<i; l = f[l][i];
		} 
		printf("%d\n", cnt+1);
	}
	return 0; 
}  
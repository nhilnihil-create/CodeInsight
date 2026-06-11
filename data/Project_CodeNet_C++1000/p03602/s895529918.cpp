#include<bits/stdc++.h>
using namespace std;
#define R register int
#define AC 400
#define LL long long

int n;
LL ans;
LL f[AC][AC], g[AC][AC];
bool z = true;

inline int read()
{
	int x = 0;char c = getchar();
	while(c > '9' || c < '0') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}

void pre()
{
	n = read();
	for(R i = 1; i <= n; i ++) 
		for(R j = 1; j <= n; j ++) 
			f[i][j] = g[i][j] = read();
}

void work()
{
	for(R k = 1; k <= n; k ++)
		for(R i = 1; i <= n; i ++)
			for(R j = 1; j <= n; j ++)
			{
				if(i == k || j == k) continue;
				if(f[i][j] > f[i][k] + f[k][j]) z = false;//如果可以凑出更短的路，那这就不是最短路了。。。。
				else if(f[i][j] == f[i][k] + f[k][j]) g[i][j] = g[j][i] = 0;
			}
	for(R i = 1; i <= n; i ++)
		for(R j = 1; j <= n; j ++) ans += g[i][j];
	if(z) printf("%lld\n", ans / 2);//因为双向边会被统计2次
	else printf("-1\n");
}

int main()
{
	//freopen("in.in", "r", stdin);
	pre();
	work();
	//fclose(stdin);
	return 0;
}
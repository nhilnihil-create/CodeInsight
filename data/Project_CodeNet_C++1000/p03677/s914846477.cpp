#include<bits/stdc++.h>
using namespace std;
#define R register int
#define AC 201000
#define LL long long

int n, m;
LL ans;
LL s[AC], k[AC], d[AC];

inline int read()
{
	int x = 0;char c = getchar();
	while(c > '9' || c < '0') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}

inline int cal(int l, int r)
{	
	if(l == r) return 0;
	if(l < r) return r - l;
	else return r + m - l;
}

inline void pre()
{
	n = read(), m = read();
	for(R i = 1; i <= n; i ++) 
	{
		s[i] = read();
		if(i > 1) ans += cal(s[i - 1], s[i]);//先计算出没有特殊按钮的代价
	}
}

inline void add(int l, int r)
{
	//printf("%d %d\n", l, r);
	if(l > r) return ;
	++ k[l], -- k[r + 1], d[r + 1] -= r - l + 1;//是要在后面减掉前面累积的
}

inline void upmax(LL &a, LL b)
{
	if(b > a) a = b;
}

void work()
{
	for(R i = 1; i < n; i ++)
	{
		if(s[i] == s[i + 1]) continue;
		if(s[i] < s[i + 1]) add(s[i] + 2, s[i + 1]);
		else add(s[i] + 2, s[i + 1] + m);
	}
	int b = 2 * m; LL maxn = 0;
	for(R i = 1; i <= b; i ++) k[i] += k[i - 1];
	for(R i = 1; i <= b; i ++) k[i] += k[i - 1] + d[i];
	for(R i = 1; i <= m; i ++) k[i] += k[i + m], upmax(maxn, k[i]);
	printf("%lld\n", ans - maxn);
}

int main()
{
	//freopen("in.in", "r", stdin);
	pre();
	work();
	//fclose(stdin);
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define bomb exit(1)
#define INF 1061109567
#define LINF 4557430888798830399ll
#define pprint(x) print(x),putchar(' ')
#define fprint(x) print(x),putchar('\n')
#define EE(x); struct edge { int nxt,to;ll w; }e[M << 1]; int head[N],ecnt = 1;\
	void add(int u,int v,ll w = 0) { e[++ecnt].w = w,e[ecnt].to = v,e[ecnt].nxt = head[u];head[u] = ecnt; }\
	void add_edge(int u,int v,ll w = 0) { add(u,v,w),add(v,u,w * x); }
#define ll long long
const double pi = acos(-1);
int mod = 1000000007;
ll Mod(ll x) { return x >= mod ? x - mod : x; }
#define eps 0.0000000001
#define sqr(x) ((x) * (x))
#define iter iterator
#define fi first
#define se second
//#define getchar() (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
//char BB[1 << 15],*SS = BB,*TT = BB;
ll read()
{
	ll x = 0;int f = 1;char ch = getchar();
	for(;!isdigit(ch);ch = getchar()) if(ch == '-') f = -1;
	for(;isdigit(ch);ch = getchar()) x = x * 10 + (ch ^ 48);
	return x * f;
}
void print(ll x)
{
	if(x < 0) putchar('-'),x = -x;
	if(x > 9) print(x / 10);putchar(x % 10 + '0');
}

const int N = 510;
int n,x[N],c[N],a[N * N];

int main()
{
	n = read();
	for(int i = 1;i <= n;i++) x[i] = read();
	for(int i = 1;i <= n * n;i++)
	{
		for(int j = 1;j <= n;j++) if(x[j] == i)
		{
			c[j]++;
			if(c[j] ^ j) { puts("No");return 0; }
			a[i] = j;
			break;
		}
		if(!a[i])
		{
			int p = 0,lc = n * n + 2;
			for(int j = 1;j <= n;j++) if(c[j] < j - 1)
				if(x[j] < lc)
					lc = x[j],p = j;
			if(p)
				a[i] = p,c[p]++;
		}
		if(!a[i])
			for(int j = 1;j <= n;j++) if(c[j] < n && x[j] < i)
			{
				a[i] = j;
				c[j]++;
				break;
			}
		if(!a[i]) { puts("No");return 0; }
	}
	puts("Yes");
	for(int i = 1;i <= n * n;i++) pprint(a[i]);
}
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<iostream>
#include<vector>

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

const int N = 100010;
ll ans,res;
ll a[N],pre[N],suf[N],tot;
int n,op[N];
int main()
{
	n = read();
	for(int i = 1;i < n;i++)
	{
		tot += (a[i] = read());
		char ch = getchar();while(ch != '+' && ch != '-') ch = getchar();
		op[i] = (ch == '+') ? 1 : -1;
	}tot += (a[n] = read());
	for(int i = n;i;i--) { suf[i] = a[i];if(~op[i]) suf[i] += suf[i + 1]; }
	for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
	res = a[1];ans = -LINF;
	for(int i = 2;i <= n;i++)
	{
		if(op[i - 1] == -1) ans = max(ans,res + pre[n] - pre[i - 1] - 2 * suf[i]);
		res += a[i] * op[i - 1];
	}ans = max(ans,res);fprint(ans);
    return 0;
}
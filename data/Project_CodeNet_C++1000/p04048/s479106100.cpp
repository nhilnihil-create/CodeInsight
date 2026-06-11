#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(register int i = l; i <= r; ++ i)

inline int read() 
{
	char cc = getchar(); int cn(0), flus(1);
	while(cc < '0' || cc > '9') {if(cc == '-') flus = -flus; cc = getchar();}
	while(cc >= '0' && cc <= '9') {cn = cn * 10 + cc - 48; cc = getchar();}
	return cn * flus;
}

const int MAXN = 1e5 + 10;
const int Mod = 998244353, G = 3;

int n, x, ans;

void solve(int len, int a)
{
//	printf("solve %d %d \n",len,a);
	if(!a) 
	{
		ans -= len;
		return ;
	}
	ans += (len) / a * a * 2;
//	printf("ans = %d \n",ans);
	solve(a, len % a);
}

signed main()
{
	n = read(), x = read();
	ans += n;
	solve(n - x, x);
	printf("%lld\n",ans);
	return 0;
}
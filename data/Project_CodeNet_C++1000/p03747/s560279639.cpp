#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	char x = getchar();
	ll lin = 0,f = 1;
	while(x < '0' || x > '9')
	{
		if(x == '-') f = -1;
		x = getchar();
	}
	while(x >= '0' && x <= '9')
	{
		lin = lin * 10 + x - '0';
		x = getchar();
	}
	return lin * f;
}
#define PII pair<ll,ll>
#define fir first
#define sec second
#define ma(a,b) make_pair(a,b)
#define maxn 1000001
ll pos[maxn],f,l,t,n,m,zhuan;
int main(){
	n = read(); l = read(); t = read();
	
	for(ll i = 1; i <= n; i++)
	{
		pos[i] = read();
		f = read();
		if(f == 2) pos[i] -= t;
		else pos[i] += t;
		if(pos[i] < 0)
			zhuan -= (-pos[i] + l - 1) / l;
		else
			zhuan += pos[i]/ l;
		pos[i] = (pos[i] % l + l) % l;
	}
	zhuan = (zhuan % n + n) % n;
	sort(pos + 1,pos + 1 + n);/*
	for(ll i = zhuan; i <= n; i++)
		printf("%lld\n",pos[i]);
	for(ll i = 1; i < zhuan; i++)
		printf("%lld\n",pos[i]);*/
			for (int i=1;i<=n;i++)
	 printf("%d\n",pos[(i+zhuan-1)%n+1]);
}
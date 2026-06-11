#include <bits/stdc++.h>
using namespace std;

inline long long read()
{
	long long x=0,f=1,c=getchar();
	while(c<48) c=='-'&&(f=-1),c=getchar();
	while(c>47) x=x*10+c-'0',c=getchar();
	return x*f;
}

typedef long long ll;
const int MAXN = 1000005;
ll p[MAXN],q[MAXN];
ll n,cnt,cntp,cntq;

inline void sol(ll n)
{
	if(!n) return;
	if(~n&1) q[++cntq]=cnt++,sol(n-1);
	else p[++cntp]=cnt++,sol(n>>1);
}

int main(int argc, char const *argv[])
{
	n=read(); sol(n); printf("%lld\n", cnt+100);
	for(ll i=1; i<=cntq; ++i) printf("%lld ", cnt-q[i]);
	for(ll i=cntp; i; --i) printf("%lld ", cnt-p[i]);
	for(ll i=1; i<=100; ++i) printf("%lld ", i);
	return 0;
}
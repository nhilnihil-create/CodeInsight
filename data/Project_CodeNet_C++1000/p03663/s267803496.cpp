#include <bits/stdc++.h>
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
typedef long long ll;
const int N=200005;
const int mod=1e9+7;
using namespace std;

/*struct node
{
	int t,next;
}adj[N<<1];
void add(int s,int t)
{
	adj[++now]=(node){t,head[s]};
	head[s]=now;
}*/
int calc(int a,int b)
{
	int ans=1,tmp=a;
	while (b)
	{
		if (b&1) ans=(ll)ans*tmp%mod;
		tmp=(ll)tmp*tmp%mod,b>>=1;
	}
	return ans;
}
inline int read()
{
	char c;int x;
	while (c=getchar(),c<'0' || c>'9');x=c^'0';
	while (c=getchar(),c>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x;
}
void write(int x)
{
	if (x==0) return;
	write(x/10);
	putchar((x%10)+'0');
}
int main()
{
	#ifdef Kay
		//freopen ("code.in","r",stdin);
		//freopen ("code.out","w",stdout);
	#endif
	int i;ll n;
	for (i=0,n=1;i<=11;i++,n*=10)
	{
		printf ("? %lld\n",n);fflush(stdout);
		char c;scanf ("\n%c",&c);
		if (c=='N') break;
	}
	if (i==12)
	{
		for (i=1,n=10;i<=11;i++,n*=10)
		{
			printf ("? %lld\n",n+1);fflush(stdout);
			char c;scanf ("\n%c",&c);
			if (c=='Y') break;
		}
		if (i==1)
		{
			printf ("? 9\n");fflush(stdout);
			char c;scanf ("\n%c",&c);
			if (c=='Y') puts("! 1");
			else puts("! 10");
			fflush(stdout);
		}
		else printf ("! %lld\n",n);fflush(stdout);
		return 0;
	}
	i--;
	ll lb=1;
	while (i--) lb*=10;
	ll rb=lb*10,mid;lb--;
	while (lb<rb-1)
	{
		mid=lb+rb>>1;
		printf ("? %lld\n",mid*10);fflush(stdout);
		char c;scanf ("\n%c",&c);
		if (c=='N') lb=mid;
		else rb=mid;
	}
	printf ("! %lld\n",rb);fflush(stdout);
	return 0;
}

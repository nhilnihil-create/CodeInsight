#include<bits/stdc++.h>
using namespace std;
#define LL long long

void read(int &x)
{
	char c=getchar(); x=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
}

const int PLUS=0;
const int MINUS=1;
const int maxn=1e5+10;

int n,a[maxn];
LL pre[maxn],suf[maxn],Ans;
bool op[maxn];

int main()
{
#ifdef h10
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int i;
	read(n);
	read(a[1]);
	op[1]=PLUS;
	for (i=2;i<=n;i++)
	{
		char c=getchar();
		while (c!='+'&&c!='-') c=getchar();
		if (c=='+') op[i]=PLUS;
		else op[i]=MINUS;
		read(a[i]);
	}
	for (i=1;i<=n;i++)
		pre[i]=pre[i-1]+(op[i]==PLUS?a[i]:-a[i]);
	for (i=n;i>=1;i--)
		suf[i]=suf[i+1]+a[i];
	Ans=pre[n];
	int last=0;
	for (i=n;i>=1;i--)
		if (op[i]==MINUS)
		{
			if (last)
				Ans=max(Ans,suf[last]+pre[i-1]-(suf[i]-suf[last]));
			last=i;
		}
	printf("%lld\n",Ans);
}

#include<cstdio>
inline void read(int&r)
{
	register char c;r=0;
	do c=getchar();while(c<'0'||c>'9');
	do r=r*10+c-'0',c=getchar();while(c>='0'&&c<='9');
}

typedef long long ll;
const int mod=1e9+7;
int x[100001],ans=1;

int main()
{
	int n,i;read(n);
	for(i=1;i<=n;i++)
	{
		read(x[i]);
		if(x[i]<=(i-1)<<1)
			ans=(ll)ans*i%mod,i--,n--;
	}
	do ans=(ll)ans*n%mod;while(--n);
	printf("%d\n",ans);
}
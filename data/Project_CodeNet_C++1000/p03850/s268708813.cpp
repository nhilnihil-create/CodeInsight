#include<cstdio>
const int N=100005;
typedef long long ll;
int n,A[N];
ll f0,f1,f2;
char op[N];
int main()
{
	scanf("%d%d",&n,A);
	for(int i=1;i<n;i++)scanf(" %c%d",op+i,A+i);
	f0=A[0];f1=f2=-(1ll<<60);
	for(int i=1;i<n;i++)
	{
		if(op[i]=='-')
		{
			f0-=A[i],f1+=A[i],f2-=A[i];
			if(f1>f2)f2=f1;
			if(f0>f1)f1=f0;
		}
		else
			f0+=A[i],f1-=A[i],f2+=A[i];
		if(f1>f0)f0=f1;
		if(f2>f1)f1=f2;
	}
	printf("%lld\n",f0);
}

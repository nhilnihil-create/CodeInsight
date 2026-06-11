#include <bits/stdc++.h>
using namespace std;

typedef long long  LL;
int n,a[100010];
LL s,s2,ans;
char op[100010];

void work()
{
	scanf("%d %d",&n,&a[1]),s=a[1];
	for (int i=2; i<=n; i++)
		{
			do  op[i]=getchar();  while ((op[i]!='+')&&(op[i]!='-'));
			scanf("%d",&a[i]);
			if (op[i]=='+')  s+=a[i];  else  s+=a[i];
		}
	ans=-1LL<<60,op[n+1]='-',s2=1LL<<60;
	for (int i=1; i<=n+1; i++)
		if (op[i]=='-')  ans=max(ans,s-s2),s2=0,s-=2*a[i];
		else  s2+=2*a[i];
	printf("%lld",max(ans,s));
}

int main()
{
	work();
	return 0;
}

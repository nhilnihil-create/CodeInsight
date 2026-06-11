#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int tn[11],L,R,tp,sm;
char c[5];

inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

main()
{
	register int i;
	for (tn[0]=i=1;i<=9;++i) tn[i]=tn[i-1]*10;
	for (i=0;i<=9;++i)
	{
		printf("? %lld\n",tn[i]);
		fflush(stdout);
		scanf("%s",c);
		if (c[0]=='N') break;
	}
	if (i>9)
	{
		for (i=1;i<=9;++i)
		{
			printf("? %lld\n",tn[i]-1);
			fflush(stdout);
			scanf("%s",c);
			if (c[0]=='Y') break;
		}
		printf("! %lld\n",tn[i-1]);
		fflush(stdout); return 0;
	} else tp=i;
	for (i=tp;i;--i)
	{
		if (i==tp) L=1; else L=0; R=9;
		while (L<R)
		{
			int mid=L+R+1>>1;
			printf("? %lld\n",(sm+tn[i-1]*mid)*10);
			fflush(stdout);
			scanf("%s",c);
			if (c[0]=='N') L=mid; else R=mid-1;
		}
		if (L<9)
		{
			printf("? %lld\n",(sm+tn[i-1]*(L+1))*10-1);
			fflush(stdout);
			scanf("%s",c);
			if (c[0]=='N')
			{
				printf("! %lld",sm+tn[i-1]*(L+1));
				fflush(stdout);
				return 0;
			}
		}
		sm+=L*tn[i-1];
	}
}
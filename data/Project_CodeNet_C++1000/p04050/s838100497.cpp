#include<cstdio>
const int N(1e5+5),M(105);
int n,m,cnt,c1,c2;
int a[M];
template<class Tp>
inline void swap(Tp &a,Tp &b)
{
	Tp t=a;
	a=b;b=t;
	return;
}
signed main()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]&1)
		{
			cnt++;
			if(cnt==1)
				c1=i;
			else if(cnt==2)
				c2=i;
			else
			{
				puts("Impossible");
				return 0;
			}
		}
	}
	if(m==1)
	{
		if(a[1]==1)
			printf("1\n1\n1\n");
		else
			printf("%d\n2\n%d 1\n",a[1],a[1]-1);
		return 0;
	}
	if(c1)
		swap(a[1],a[c1]);
	if(c2)
		swap(a[m],a[c2]);
	for(i=1;i<=m;i++)
		printf("%d ",a[i]);
	putchar('\n');
	printf("%d\n",m-(a[1]==1));
	if(a[1]>1)
		printf("%d ",a[1]-1);
	for(i=2;i<m;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[m]+1);
	return 0;
}
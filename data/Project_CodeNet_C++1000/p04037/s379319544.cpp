#include<cstdio>
#include<algorithm>
int n,a[100005];
bool comp(int a,int b){return a>b;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(a+1,a+1+n,comp);
	for(int i=2;i<=n;i++)if(a[i]<i)
	{
		//从(i-1,i-1)向上走
		if((a[i-1]-i+1)&1){printf("First\n");return 0;}
		int j=i;while(a[j]==i-1)j++;
		if((j-i)&1){printf("First\n");return 0;}
		printf("Second\n");return 0;
	}if((a[n]-n)&1)printf("First\n");else printf("Second\n");
}
#include<cstdio>
#include<cstring>
const int N=1e5+12;
int map[N];int n;
int gcd(int a,int b) 
{
	if(!b) return a;
	return gcd(b,a%b); 
}
int dfs(int x)
{
	int tot=0,flag=1;
	for(int i=1;i<=n;i++) 	
		if(map[i]%2)
		{
			map[i]--;
			break;
		}
	int gc=map[1];
	for(int i=2;i<=n;i++) gc=gcd(gc,map[i]);
	for(int i=1;i<=n;i++)
	{
		map[i]/=gc;
		if(map[i]%2==0) tot++;
		if(map[i]==1) flag=0;
	}
	if(tot%2) return !x;
	if(!flag||n-tot>1) return x;
	dfs(x^1);
	
}
int main()
{	
	scanf("%d",&n);
	int sum=0;
	int sum_flag=0,flag1=1;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&map[i]);
		if(map[i]==1) flag1=0;
		if(map[i]%2==0) sum++;
		else sum_flag++;
//		printf("std:: %d %d %d\n",sum,sum_flag,flag1);
	}
	if(sum%2==1) printf("First\n");
	else
	{
		if(!flag1||sum_flag>=2) printf("Second\n");
		else if(dfs(1)) printf("First\n");
		else printf("Second\n");
	}
	return 0;
}
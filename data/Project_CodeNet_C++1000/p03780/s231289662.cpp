# include<iostream>
# include<cstdio>
# include<cmath>
# include<algorithm>
# include<cstring>
using namespace std;
const int mn = 5005;
int a[mn];
bool vis[mn];
int n,k,s;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
	  scanf("%d",&a[i]);
	  a[i]=min(a[i],k);
	  s+=a[i];
	}
	sort(a+1,a+1+n);
	vis[0]=1;
	for(int i=n;i>=0;i--)
	{
		bool flag=false;
		for(int j=k-1;j>=k-s && j>=0;j--)
		   if(vis[j]) {
		   flag=true;
		   break;
		   }
		if(!flag) 
		{
			printf("%d",i);
			return 0;
		}
		for(int j=k;j>=a[i];j--)
		   vis[j]=(vis[j] | vis[j-a[i]]);
		s-=a[i];
	}
	return 0;
}
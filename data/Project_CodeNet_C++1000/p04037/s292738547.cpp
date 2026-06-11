#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
inline void re(int &x)
{
	x=0;bool flag=false;
	char c=getchar();
	while(c<'0'||c>'9'){
		flag= c=='-';
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	if(flag)x=-x;
	return ;
}
int a[100010],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]<=i)
		{
			int r=i;
			while(a[r+1]==i)r++;
			ans=(((a[i]-i+1)&1)&((r-i+1)&1))^1;
			break;
		}
	}
	if(ans)printf("First\n");
	else printf("Second\n");
	return 0;
}
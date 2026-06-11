#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,num[2],a[100005],Num=0;
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1,greater<int>());
	for(int i=1,j;i<=n+1;++i) if(i-1>=a[i])
	{
		int ans1=a[i-1]-(i-2);
		for(j=i;a[j]==i-1;++j);
		int ans2=j-(i-2)-1;
		puts((ans1&1)&&(ans2&1)?"Second":"First");
		return 0;
	}	
}


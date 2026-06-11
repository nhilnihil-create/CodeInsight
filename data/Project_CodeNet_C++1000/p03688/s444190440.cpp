#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T& t)
{T f=1;char ch=getchar();t=0;
while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
while(ch>='0'&&ch<='9')t=t*10+ch-'0',ch=getchar();t*=f;}
template <typename T,typename... Args>
inline void read(T& t, Args&... args)
{read(t);read(args...);}
int T;
int n,num[100005];
int a,b,na,nb;
int work()
{
	read(n);
	a=1e9;b=-1e9;
	for(int i=1;i<=n;i++)
	{
		read(num[i]);
		if(num[i]>n-1)return printf("No\n"),0;
		a=min(a,num[i]);b=max(b,num[i]);
	}
	if(a==b)
	{
		if(a==n-1)return printf("Yes\n"),0;
		if(n>=a*2)return printf("Yes\n"),0;
		return printf("No\n"),0;
	}
//	printf("a=%d b=%d na=%d nb=%d\n",a,b,na,nb);	
	if(a!=b-1&&a!=b)return printf("No\n"),0;
	na=nb=0; 
	for(int i=1;i<=n;i++)
		na+=num[i]==a,nb+=num[i]==b;
	if(b-na<=0)return printf("No\n"),0;
	if(nb>=(b-na)*2)return printf("Yes\n"),0;
	printf("No\n");return 0;
}
int main()
{
	work();
	return 0;
}

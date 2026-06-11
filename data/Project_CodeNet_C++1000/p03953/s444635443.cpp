#include<iostream>
#include<cstdio>
using namespace std;
int n,m,top,st[101010];
int id[101010],bok[101010];
long long k,ans[101010],a[101010];
void change(int x)
{
	top=0;
	st[++top]=x;bok[x]=1;
	while(!bok[id[x]]) bok[id[x]]=1,st[++top]=x=id[x];
	int k1=k%top;
	for(int i=1;i<=top-k1;i++)
		ans[st[i]]=a[st[i+k1]]-a[st[i+k1]-1];
	for(int i=top-k1+1;i<=top;i++)
		ans[st[i]]=a[st[i-top+k1]]-a[st[i-top+k1]-1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),id[i]=i;
	scanf("%d%lld",&m,&k);
	for(int i=1,x;i<=m;i++)
	{
		scanf("%d",&x);
		swap(id[x+1],id[x]);
	}
	for(int i=1;i<=n;i++)
	if(!bok[i]) change(i);
	printf("%lld.0\n",a[1]);
	for(int i=2;i<=n;i++)
		printf("%lld.0\n",a[i]=a[i-1]+ans[i]);
	return 0;
}
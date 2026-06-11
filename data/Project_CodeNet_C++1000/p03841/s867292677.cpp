#include <bits/stdc++.h>

const int N=505;
int n,a[N],b[N],c[N*N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i),c[a[i]]=b[i]=i;
	std::sort(b+1,b+n+1,[](int x,int y){return a[x]<a[y];});
	for(int i=1,p=1;i<=n;++i)
	{
		for(int j=1;j<b[i];c[p]=b[i],++j)while(c[p])++p;
		if(p>a[b[i]])return puts("No"),0;
	}
	for(int i=n,p=n*n;i>=1;--i)
	{
		for(int j=b[i]+1;j<=n;c[p]=b[i],++j)while(c[p])--p;
		if(p<a[b[i]])return puts("No"),0;
	}
	puts("Yes");
	for(int i=1;i<=n*n;++i)printf("%d%c",c[i],i==n*n?'\n':' ');
	return 0;
}
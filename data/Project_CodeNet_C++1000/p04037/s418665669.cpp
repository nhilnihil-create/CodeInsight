#include<cctype>
#include<cstdio>
#include<algorithm>
#include<functional>
int a[100007];
int read(){int x;scanf("%d",&x);return x;}
int main()
{
    int n=read(),ans=0;
    for(int i=1;i<=n;++i) a[i]=read();
    std::sort(a+1,a+n+1,std::greater<int>());
    for(int i=1;i<=n;++i)
	if(i+1>a[i+1])
	{
	    for(int j=i+1;a[j]==i;++j) ans^=1;
	    return ans|=(a[i]-i)&1,puts(ans?"First":"Second"),0;
	}
}

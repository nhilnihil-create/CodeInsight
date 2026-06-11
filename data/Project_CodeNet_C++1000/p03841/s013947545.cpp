#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int read()
{
    char c=getchar();int f=1,sum=0;
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
int n,tot;
int a[505*505],b[505],cnt[505],x[505];
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[x[i]=read()]=i;
	for(int i=1;i<=n*n;i++) if(a[i]) b[++tot]=a[i];
	for(int i=1;i<=n;i++) cnt[i]=i-1;
	for(int i=1;i<=n*n;i++)if(!a[i])for(int j=1;j<=n;j++)if(cnt[b[j]]){a[i]=b[j];cnt[b[j]]--;break;}
	for(int i=1;i<=n;i++) cnt[i]=n-i;
	for(int i=n*n;i>=1;i--)if(!a[i])for(int j=n;j>=1;j--)if(cnt[b[j]]){a[i]=b[j];cnt[b[j]]--;break;}
	bool flag=1;
	for(int i=1,num=0,j;i<=n;i++,num=0)
	{
		for(j=1;j<=n*n;j++) if(a[j]==i){num++;if(num==i) break;}
		if(j!=x[i]){flag=0;break;}
	}
	puts(flag?"Yes":"No");
	if(flag) for(int i=1;i<=n*n;i++) printf("%d ",a[i]);
	return 0;
}

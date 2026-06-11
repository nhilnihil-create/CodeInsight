#include<bits/stdc++.h>
using namespace std;
int n;
int a[2100000];
int l[2100000];
int r[2100000];
long long ans=0;
int main()
{
	scanf("%d",&n);
    r[0]=1;
    l[n+1]=n;
    for(int i=1;i<=n;i++)
    {
       	int x;
       	scanf("%d",&x);
        l[i]=i-1;
        r[i]=i+1;
        a[x]=i;
    }
    for(int i=n;i>=1;i--)
    {
        ans+=1LL*i*(a[i]-l[a[i]])*(r[a[i]]-a[i]);
        r[l[a[i]]]=r[a[i]];
		l[r[a[i]]]=l[a[i]];
    }
	printf("%lld\n",ans);
    return 0;
}
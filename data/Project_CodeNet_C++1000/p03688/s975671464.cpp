#include<bits/stdc++.h>
using namespace std;
#define reg register
#define ll long long
inline ll read()
{
	ll x=0,w=0;char ch=getchar();
	while(!isdigit(ch))w|=ch=='-',ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w?-x:x;
}
int n,mi,ma,A,B;
int a[100005];
int main()
{
    n=read();mi=n;ma=0;
    reg int i;
    for(i=1;i<=n;++i)
    {
        a[i]=read();
        mi=min(mi,a[i]);
        ma=max(ma,a[i]);
    }
    if(ma!=mi)
    {
        if(ma!=mi+1){puts("No");return 0;}
        for(i=1;i<=n;++i)if(a[i]==mi)A++;else B++;
        if(ma<=A){puts("No");return 0;}
        if(n-A>=2*(ma-A))puts("Yes");else puts("No");
        return 0;
    }
    if(ma==n-1||ma==1){puts("Yes");return 0;}
    if(ma*2<=n){puts("Yes");return 0;}puts("No");
	return 0;
}

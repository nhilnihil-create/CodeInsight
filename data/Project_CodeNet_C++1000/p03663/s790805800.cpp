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
ll ans;
char s[10];
inline void query(ll x)
{if(x==1){s[0]='Y';return ;}printf("? %lld\n",x);fflush(stdout);scanf("%s",s);}
inline int check(ll x)
{
    reg ll y=x*10;
    reg int l=0,r=10,mid;
    while(l<r-1)
    {
        mid=(l+r)>>1;
        query(y+mid);
        if(s[0]=='N')r=mid;
        else l=mid;
    }
    return r-1;
}
int main()
{
    reg ll x;reg int i;
    x=1;reg int len=15;
    for(i=1;i<=10;++i)
    {
        query(x);
        if(s[0]=='N')
        {
            len=i-1;break;
        }x*=10;
    }
    if(len==15)
    {
        x=9;
        for(i=1;i<=10;++i)
        {
            query(x);
            if(s[0]=='Y')
            {
                len=i;break;
            }x=x*10+9;
        }
        if(len>1)
        {
            ans=1;
            for(i=1;i<len;++i)ans=ans*10;
            printf("! %lld\n",ans);return 0;
        }
    }
    for(i=1;i<len;++i)
        x=check(ans),ans=ans*10+x;
    if(len==1)
    {
        for(i=9;i>=1;--i)
        {
            query(i*10+1);
            if(s[0]=='N'){printf("! %d\n",i+1);exit(0);}
        }
        puts("! 1");return 0;
    }
    for(i=0;i<=9;++i)
    {
        x=(ans*10+i)*10+1;
        query(x);
        if(s[0]=='Y')
        {
            ans=ans*10+i;
            printf("! %lld\n",ans);exit(0);
        }
    }
	return 0;
}

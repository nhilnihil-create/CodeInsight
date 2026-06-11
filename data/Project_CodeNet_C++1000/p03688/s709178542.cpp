#include<bits/stdc++.h>
using namespace std;
int n,a[1000005];
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
#define gc getchar
inline int read()
{
    int ret=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){ret=ret*10+c-48;c=gc();}
    if(f)return -ret;return ret;
}
int main()
{
    n=read();
    int mn=n+1,mx=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    if(mx>mn+1){puts("No");return 0;}
    if(mx==mn)
    {
        if(mn==n-1){puts("Yes");return 0;}
        if(2*mn<=n){puts("Yes");return 0;}
        puts("No");return 0;
    }
    else
    {
        int cnt=0;
        for(int i=1;i<=n;i++)cnt+=(a[i]==mn);
        if(mn<cnt){puts("No");return 0;}
        if(n-cnt<2*(mx-cnt)){puts("No");return 0;}
        else{puts("Yes");return 0;}
    }
    return 0;
}
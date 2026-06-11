#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
typedef long long LL;
int id[maxn],s1[maxn],t1[maxn],t2[maxn];
LL d[maxn],d2[maxn];
int read()
{
    char ch=getchar();
    int x=0,f=1;
    while(!isdigit(ch))
    {
        f=(ch=='-')?-f:f;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return f<0?-x:x;
}
int main()
{
    int n=read();
    for(int i=1;i<=n;i++) d[i]=read();
    LL left=d[1];
    for(int i=1;i<n;i++) d[i]=d[i+1]-d[i];
    LL k;int m=read();
    scanf("%lld",&k);
    for(int i=1;i<n;i++) id[i]=i;
    for(int i=1;i<=m;i++)
    {
        int t=read();
        swap(id[t-1],id[t]);
    }
    for(int i=1;i<n;i++) s1[id[i]]=i;
    int *cur=t1,*nxt=t2;
    for(int i=1;i<n;i++) cur[i]=s1[i];
    int w=0;
    while((k>>w)>1)w++;
    while(w>0)
    {
        --w;
        for(int i=1;i<n;i++) nxt[i]=cur[cur[i]];
        swap(nxt,cur);
        if((k>>w)&1)
        {
            for(int i=1;i<n;i++) nxt[i]=s1[cur[i]];
            swap(nxt,cur);
        }
    }
    for(int i=1;i<n;i++) d2[cur[i]]=d[i];
    printf("%lld\n",left);
    for(int i=1;i<n;i++) printf("%lld\n",left+=d2[i]);
    return 0;
}

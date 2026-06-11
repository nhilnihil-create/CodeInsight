#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int n,m,a[100010];
LL ans=(1LL<<60),tot=0;
int pre[200010];
bool ty=true;
struct node{
    int x,k,op;//坐标，哪一个， 左/右端点
}b[400010];int num=0,len;
bool cmp(node a,node b) {return a.x<b.x;}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]!=i) ty=false;
    }
    if(ty) {printf("%d\n",n-1);return 0;}
    len=n-1;
    for(int i=1;i<n;i++)
    {
        int l=a[i],r=a[i+1];if(l>r) l-=m;
        tot+=(LL)(r-l);
        if(l==r||l+1==r) continue;
        pre[i]=r-l-1;
        if(l>0)
        { 
            b[++num].x=l;b[num].k=i;b[num].op=0;
            b[++num].x=r;b[num].k=i;b[num].op=1;
        }
        else
        {
            l+=m;
            if(l<m-1)
            {
                pre[++len]=m-l-1;
                b[++num].x=l;b[num].k=len;b[num].op=0;
                b[++num].x=m;b[num].k=len;b[num].op=1;
            }
            b[++num].x=r;b[num].k=i;b[num].op=1;
        }
    }
    sort(b+1,b+num+1,cmp);
    int p=num,cnt=0;ans=tot;
    while(p!=0)
    {
        while(1)
        {
            if(p!=num&&b[p].x!=b[p+1].x) tot+=(LL)cnt*(LL)(b[p+1].x-b[p].x);
            if(b[p].op==1) tot-=(LL)pre[b[p].k],cnt++;
            if(b[p].op==0) cnt--,tot--;
            if(p==1||b[p-1].x!=b[p].x) break;
            p--;
        }
        ans=min(ans,tot);p--;
    }
    printf("%lld\n",ans);
}
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1e5+10;
int n,l,t;
struct ant
{
    int x,w,id;
} ants[maxn];
int x[maxn],w[maxn],id[maxn],ans[maxn];
bool cmpant(const ant& A,const ant& B)
{
    if(A.x!=B.x) return A.x<B.x;else return A.w<B.w;
}
int main()
{
    scanf("%d%d%d",&n,&l,&t);
    for(int i=1;i<=n;i++) scanf("%d%d",x+i,w+i);
    for(int i=1;i<=n;i++)
    {
        ants[i].id=i;
        ants[i].w=w[i];
        if(w[i]==1) ants[i].x=(x[i]+t)%l;else ants[i].x=((x[i]-t)%l+l)%l;
    }
    sort(ants+1,ants+n+1,cmpant);
    vector<int> rev;
    int d;
    t*=2;
    if(w[1]==1)
    {
        for(int i=2;i<=n;i++) if(w[i]==2) rev.push_back(x[i]-x[1]);
        if(rev.size()==0) d=0;else
        {
            d=(t/l)*rev.size();
            t%=l;
            for(int i=0;i<rev.size();i++) if(rev[i]<t)d++;
        }
    } else
    {
        for(int i=n;i>1;i--) if(w[i]==1) rev.push_back(x[1]-x[i]+l);
        if(rev.size()==0) d=0;else
        {
            d=(t/l)*rev.size();
            t%=l;
            for(int i=0;i<rev.size();i++) if(rev[i]<t)d++;
        }
        d=-d;
    }
    int id1;
    for(int i=1;i<=n;i++) if(ants[i].id==1) id1=i;
    id[id1]=((1+d)%n+n)%n;
    for(int i=id1+1;i<=n;i++) id[i]=(id[i-1]+1)%n;
    id[1]=(id[n]+1)%n;
    for(int i=2;i<id1;i++) id[i]=(id[i-1]+1)%n;
    for(int i=1;i<=n;i++) if(id[i]>0) ans[id[i]]=ants[i].x;else ans[n]=ants[i].x;
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}

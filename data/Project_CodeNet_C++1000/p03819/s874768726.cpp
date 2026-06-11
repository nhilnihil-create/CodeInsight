#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
const int M=3e5+5;
struct d{int l,r;}a[M];
bool cmp(d a,d b){return a.r-a.l<b.r-b.l;}
int sum[M];
void upd(int pos,int x){for(int i=pos;i<M;i+=lowbit(i))sum[i]+=x;return ;}
int que(int pos){int res=0;for(int i=pos;i>0;i-=lowbit(i))res+=sum[i];return res;}
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+1+n,cmp);
    for(int d=1,j=1;d<=m;d++)
    {
        while(j<=n&&a[j].r-a[j].l<d-1)
        {
            upd(a[j].l,1);
            upd(a[j].r+1,-1);
            j++;
        }
        int ans=n-j+1;
        for(int i=d;i<=m;i+=d)ans+=que(i);
        printf("%d\n",ans);
    }
}

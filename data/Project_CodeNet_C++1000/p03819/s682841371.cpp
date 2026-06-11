#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
struct node{int l,r;
}a[300010];
bool cmp(node x,node y){return x.r-x.l<y.r-y.l;}

int tree[100010];
void add(int id,int x){for(;id<=m;id+=id&-id) tree[id]+=x;}
int query(int id){int re=0;for(;id;id-=id&-id) re+=tree[id];return re;}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+n+1,cmp);
    for (int i=1,j=0;i<=m;i++)
    {
        int cnt=0;
        for (int t=i;t<=m;t+=i) cnt+=query(t);
        printf("%d\n",cnt+n-j);
        while (j<n&&a[j+1].r-a[j+1].l<=i)
        {
            add(a[j+1].l,1);
            add(a[j+1].r+1,-1);
            j++;
        }
    }
}
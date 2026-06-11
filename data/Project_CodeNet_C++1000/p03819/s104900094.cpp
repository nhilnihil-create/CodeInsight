#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,tree[300005];
struct node{int l,r,len;}q[300005];
bool cmp(node t1,node t2){return t1.len<t2.len;}
int lowbit(int x){return x&-x;}
void add(int x,int y){for (int i=x;i<=m;i+=lowbit(i))tree[i]+=y;}
int query(int x){int s=0;for (int i=x;i>0;i-=lowbit(i))s+=tree[i];return s;}
int main()
{
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      scanf("%d%d",&q[i].l,&q[i].r),q[i].len=q[i].r-q[i].l+1;
   sort(q+1,q+n+1,cmp);
   for (int i=1,k=1;i<=m;i++)
   {
      for (;(k<=n && q[k].len<i);k++)
         add(q[k].l,1),add(q[k].r+1,-1);
      int ans=n-k+1; 
      for (int j=i;j<=m;j+=i) ans+=query(j);
      printf("%d\n",ans);
   }
   return 0; 
}
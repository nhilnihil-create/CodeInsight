#include<bits/stdc++.h>
#define N 200005 
using namespace std;
map<int,int>Map;
struct node{
    int l, r;
    long long sum;
}tree[4*N];
long long n,m,k,sum;
long long ans;
long long a[N],b[N];
void pushup(int x){
    tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
}
void build(int x,int l,int r){
    tree[x].l=l;tree[x].r=r;
    if(l==r){tree[x].sum=0;return;}
    int mid=(l+r)/2;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    pushup(x);
}
void change(int n, int x, int y){
    if(tree[n].l>x||tree[n].r<x)return;
    if(tree[n].l==x&&tree[n].r==x){tree[n].sum+=y;return;}
    change(n*2,x,y);
    change(n*2+1,x,y);
    pushup(n);
}
void query(int x,int l,int r){
    if(tree[x].l>r||tree[x].r<l)return;
    if(tree[x].l>=l&&tree[x].r<=r){ans+=tree[x].sum;return;}
    query(x*2,l,r);
    query(x*2+1,l,r);
}
int main(){
    scanf("%d%d",&n,&k);
    sum=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]=a[i]-k;a[i]=a[i]+a[i - 1];
        b[i]=a[i];
    }
    sort(b,b+n+1);
    m=unique(b,b+n+1)-b;
    for(int i=0;i<=n;i++)a[i]=lower_bound(b,b+m+1,a[i])-b+1;
    build(1,0,n);
    for(int i=0;i<=n;i++){
        ans=0;
        query(1,0,a[i]);
        sum+=ans;
        change(1,a[i],1);
    }
    printf("%lld\n",sum);
    return 0;
}

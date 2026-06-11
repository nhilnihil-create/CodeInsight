#include<bits/stdc++.h>
#define N 100100
using namespace std;
int n,m,pos=1;
struct QAQ{
    int l,r,sum,add;
}t[N<<2];
struct QWQ{
	int l,r;
}a[N*3];
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0'){
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return s*w;
}
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
inline void push_up(int p){t[p].sum=t[ls(p)].sum+t[rs(p)].sum;}
inline void spread(int p){
    if(t[p].add){
        t[ls(p)].sum+=t[p].add*(t[ls(p)].r-t[ls(p)].l+1);
        t[rs(p)].sum+=t[p].add*(t[rs(p)].r-t[rs(p)].l+1);
        t[ls(p)].add+=t[p].add;
        t[rs(p)].add+=t[p].add;
        t[p].add=0;
    }
}
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r) return;
    int mid=(t[p].l+t[p].r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
}
void change(int p,int l,int r,int x){
    if(l<=t[p].l&&t[p].r<=r){
        t[p].add+=x;
        t[p].sum+=(t[p].r-t[p].l+1)*x;
        return;
    }
    spread(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l<=mid)change(ls(p),l,r,x);
    if(r>mid) change(rs(p),l,r,x);
    push_up(p);
}
int ask(int p,int l,int r){
    if(l<=t[p].l&&t[p].r<=r){
        return t[p].sum;
    }
    spread(p);
    int mid=(t[p].l+t[p].r)>>1,ans=0;
    if(l<=mid)ans+=ask(ls(p),l,r);
    if(r>mid) ans+=ask(rs(p),l,r);
    return ans;
}
inline bool cmp(QWQ x,QWQ y){
	return x.r-x.l<y.r-y.l;
}
int main(){
    n=read();m=read();
    build(1,1,m);
	for(register int i=1;i<=n;i++){
		a[i].l=read();
		a[i].r=read();
	}
	sort(a+1,a+n+1,cmp);
	for(register int i=1;i<=m;i++){
		while(a[pos].r-a[pos].l<i&&pos<=n){
			change(1,a[pos].l,a[pos].r,1);
			pos++;
		}
		int ans=n-pos+1;
		for(int j=i;j<=m;j+=i){
			ans+=ask(1,j,j);
		}
		printf("%d\n",ans);
	}
    return 0;
}

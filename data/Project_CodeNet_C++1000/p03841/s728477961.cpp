#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 520
#define mid ((l+r)>>1)
using namespace std;
int read(){
    int nm=0,fh=1; char cw=getchar();
    for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
    for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
    return nm*fh;
}
int p[M*M*4],od[M],pos[M],n,m,ans[M*M];
bool cmp(int x,int y){return pos[x]<pos[y];}
void fad(){puts("No");exit(0);}
void ins(int x,int l,int r,int pos,int num){
    if(p[x]==r-l+1) return fad();
    p[x]++; if(l==r){ans[l]=num;return;}
    if(pos<=mid) ins(x<<1,l,mid,pos,num);
    else ins(x<<1|1,mid+1,r,pos,num);
}
void add_pre(int x,int l,int r,int rs,int num){
    if(l>rs||p[x]==r-l+1) return fad();
    p[x]++; if(l==r){ans[l]=num;return;}
    if(p[x<<1]<mid-l+1) add_pre(x<<1,l,mid,rs,num);
    else add_pre(x<<1|1,mid+1,r,rs,num);
}
void add_suf(int x,int l,int r,int ls,int num){
    if(r<ls||p[x]==r-l+1) return fad();
    p[x]++; if(l==r){ans[l]=num;return;}
    if(p[x<<1|1]<r-mid) add_suf(x<<1|1,mid+1,r,ls,num);
    else add_suf(x<<1,l,mid,ls,num);
}
int main(){
    n=read(),m=n*n;
    for(int i=1;i<=n;i++) pos[i]=read(),od[i]=i,ins(1,1,m,pos[i],i);
    sort(od+1,od+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<od[i];j++) add_pre(1,1,m,pos[od[i]],od[i]);
    }
    for(int i=n;i>0;i--){
        for(int j=od[i]+1;j<=n;j++) add_suf(1,1,m,pos[od[i]],od[i]);
    }
    puts("Yes");
    for(int i=1;i<=m;i++) printf("%d%c",ans[i],i<m?' ':'\n');
    return 0;
}

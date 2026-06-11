#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=3e5+5,maxm=1e5+5;
int m,n;
struct Pair{
    int l,r;
}p[maxn];
bool Cmp(Pair a,Pair b){return a.r-a.l<b.r-b.l;}
    int a[maxn],s[maxn*4],tag[maxn*4];
    void build(int node,int begin,int end){
        tag[node]=0;
        if(begin==end){
            s[node]=a[begin];
        }else{
            build(2*node,begin,(begin+end)/2);
            build(2*node+1,(begin+end)/2+1,end);
            s[node]=s[2*node]+s[2*node+1];
        }
    }
    void pushdown(int node,int begin,int end){
        if(begin==end){
            s[node]+=tag[node];
            a[begin]=s[node];
        }else{
            tag[2*node]+=tag[node];
            tag[2*node+1]+=tag[node];
            s[node]+=tag[node]*(end-begin+1);
        }
        tag[node]=0;
    }
    void Change(int node,int begin,int end,int left,int right,int add){
        if(begin>=left&&end<=right){
            tag[node]+=add;
        }else{
            pushdown(node,begin,end);
            int m=(begin+end)/2;
            if(!(right<begin||left>m)){
                Change(2*node,begin,m,left,right,add);
            }
            if(!(right<m+1||left>end)){
                Change(2*node+1,m+1,end,left,right,add);
            }
        }
    }
    int query(int node,int begin,int end,int idx){
        pushdown(node,begin,end);
        if(begin==end)return a[begin];
        int m=(begin+end)/2;
        if(idx<=m)return query(2*node,begin,m,idx);
        return query(2*node+1,m+1,end,idx);
    }
int main(){
    scanf("%d%d",&n,&m);
    build(1,1,m);
    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i].l,&p[i].r);
    sort(p,p+n,Cmp);
    int i=0;
    for(int d=1;d<=m;d++){
        while(i<n&&p[i].r-p[i].l<d){
            Change(1,1,m,p[i].l,p[i].r,1);
            i++;
        }
        int ans=n-i;
        for(int k=d;k<=m;k+=d){
            ans+=query(1,1,m,k);
        }
        printf("%d\n",ans);
    }
    return 0;
}
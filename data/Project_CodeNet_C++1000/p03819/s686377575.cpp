#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int _=3e5+10;
int n,m,c[_];
inline void add(int x,int y){
    for(;x<=m;x+=x&(-x))c[x]+=y;
}
inline int sum(int x){
    int res=0;
    for(;x;x-=x&(-x))res+=c[x];
    return res;
}
struct node{
    int l,r,len;
}e[_];
inline bool cmp(node t1,node t2){
    return t1.len<t2.len;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&e[i].l,&e[i].r);
        e[i].len=e[i].r-e[i].l+1;
    }
    sort(e+1,e+1+n,cmp);
    int num=1;
    for(int d=1;d<=m;d++){
        while(e[num].len<d&&num<=n)
        { add(e[num].l,1); add(e[num].r+1,-1); num++; }
        int ans=n-num+1;
        for(int j=1;j*d<=m && d;j++)ans+=sum(j*d);
        
        printf("%d\n",ans);
    }
}
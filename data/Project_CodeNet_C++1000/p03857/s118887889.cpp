#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int fa[maxn],ma[maxn];
void init(){
    for (int i=0;i<maxn;i++) fa[i]=i,ma[i]=i;
}
int fnd(int *k,int x){
    return x==k[x]?x:k[x]=fnd(k,k[x]);
}
void Union(int *k,int x,int y){
    int fx=fnd(k,x),fy=fnd(k,y);
    if(fx!=fy) k[fy]=fx;
}
map<pair<int,int>,int>mp;
int main(){
    int n,k,l,u,v;
    init();
    scanf("%d%d%d",&n,&k,&l);
    while(k--){
        scanf("%d%d",&u,&v);
        Union(fa,u,v);
    }
    while(l--){
        scanf("%d%d",&u,&v);
        Union(ma,u,v);
    }
    for (int i=1;i<=n ; i++)  mp[make_pair(fnd(fa,i),fnd(ma,i))]++;
    for (int i=1;i<n;i++) printf("%d ",mp[make_pair(fnd(fa,i),fnd(ma,i))]);
    printf("%d\n",mp[make_pair(fnd(fa,n),fnd(ma,n))]);
    return 0;
 
}
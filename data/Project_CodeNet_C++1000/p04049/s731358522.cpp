#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#define fo(i,a,b) for(i=a;i<=b;i++)

using namespace std;

const int maxn=2005;

int dis[maxn],fi[maxn],ne[maxn*2],dui[maxn*2],qc[maxn],duii[maxn*2];
bool bz[maxn];
int i,j,k,l,m,n,x,y,z,ans,tot,now;

void add(int x,int y){
    if (fi[x]==0) fi[x]=++now; else ne[qc[x]]=++now;
    qc[x]=now; dui[now]=y; duii[now]=x;
}
void dfs(int x){
    bz[x]=true;
    int i=fi[x];
    while (i){
        if (bz[dui[i]]==true){
            i=ne[i];
            continue;
        }
        dis[dui[i]]=dis[x]+1;
        dfs(dui[i]);
    }
}
void work1(){
    k=k/2;
    ans=n;
    fo(i,1,n){
        memset(bz,false,sizeof(bz));
        dis[i]=0;
        dfs(i); tot=0;
        fo(j,1,n) if (dis[j]>k) tot++;
        ans=min(ans,tot);
    }
}
void work2(){
    k=(k+1)/2;
    ans=n;
    fo(i,1,now){
        memset(bz,false,sizeof(bz));
        dis[dui[i]]=dis[duii[i]]=1;
        bz[dui[i]]=bz[duii[i]]=true;
        dfs(dui[i]);
        dfs(duii[i]); tot=0;
        fo(j,1,n) if (dis[j]>k) tot++;
        ans=min(ans,tot);

    }
}
int main(){
   // freopen("c.in","r",stdin);
   // freopen("c.out","w",stdout);
    scanf("%d%d",&n,&k);
    fo(i,1,n){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    if (k%2==0) work1(); else work2();
    printf("%d",ans);
    return 0;
}

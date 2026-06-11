#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
struct edge{
    int v,next;
}a[200003];
int n,k,x,ans,tot,num[100003],head[100003],dis[100003];
inline void add(int u,int v){
    a[++tot].v=v,a[tot].next=head[u],head[u]=tot;
}
void dfs(int u){
    dis[u]=1;
    for(int tmp=head[u];tmp;tmp=a[tmp].next){
        int v=a[tmp].v;
        dfs(v);
        dis[u]=max(dis[u],dis[v]+1);
    }
    if(dis[u]>=k&&num[u]!=1){
        ans++;
        dis[u]=0;
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(i==1){
            if(num[i]!=1)ans++;
            num[1]=1;
        }else{
            add(num[i],i);
        }
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
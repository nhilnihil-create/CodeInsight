#include<bits/stdc++.h>
using namespace std;
int n,k;
const int maxn=2e3+10;
const int maxm=4e3+10;
int head[maxn];
int cnt;
int ans;
struct node{
    int u,v,to;
}ed[maxm];
void init(){
    cnt=0;
    for(int i=1;i<=n;++i){
        head[i]=-1;
    }
}
void add(int u,int v){
    ed[++cnt].u=u;
    ed[cnt].v=v;
    ed[cnt].to=head[u];
    head[u]=cnt;
}
void dfs(int x,int pre,int d){
//    cout<<x<<" "<<pre<<" "<<d<<endl;
    if(d>k)ans++;
    for(int i=head[x];i!=-1;i=ed[i].to){
        int u=x;
        int v=ed[i].v;
        if(v==pre)continue;
        dfs(v,u,d+1);
    }
}
int main(){
    cin>>n>>k;
    int nn=n;
    int a,b;
    init();
    ans=0;
    while(--nn){
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    int res=0x3f3f3f3f;
    if(!(k&1)){
        k>>=1;
        for(int i=1;i<=n;++i){
            ans=0;
            dfs(i,-1,0);
            res=min(res,ans);
        }
        cout<<res<<endl;
    }
    else{
        k>>=1;
        for(int i=1;i<=2*n-3;i+=2){
            ans=0;
            int u=ed[i].u;
            int v=ed[i].v;
            int tmp=0;
            dfs(u,v,0);
            tmp+=ans;
            ans=0;
            dfs(v,u,0);
            tmp+=ans;
//            cout<<tmp<<endl;
            res=min(res,tmp);
        }
        cout<<res<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2e3+3;
vector<int>g[N];
bool leaf[N];
int sz[N],maybe[N],k,cnt,ans=1e5+5;
void dfs(int x,int dep,int par){
    cnt++;
    for(auto&y:g[x]){
        if(y!=par&&dep<k/2){
            dfs(y,dep+1,x);
        }
        else if(y!=par&&dep==k/2){
            maybe[y]=1;
        }
    }
}
int dfs2(int curr,int par){
    int a=maybe[curr];
    for(auto&y:g[curr]){
        if(y!=par){
            a+=dfs2(y,curr);
        }
    }
    return a;
}
int main()
{
    int n;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
        sz[x]++;
        sz[y]++;
    }
    if(k==1){
        printf("%d\n",n-2);
        return 0;
    }
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=1;j<=n;j++){
            maybe[j]=0;
        }
        dfs(i,0,-1);
        int mx=0;
        if(k%2){
            for(auto&ne:g[i]){
                mx=max(mx,dfs2(ne,i));
            }
            cnt+=mx;
        }
        ans=min(ans,n-cnt);
        //printf("i:%d ans[i]:%d\n",i,n-cnt);
    }
    printf("%d\n",ans);
    return 0;
}

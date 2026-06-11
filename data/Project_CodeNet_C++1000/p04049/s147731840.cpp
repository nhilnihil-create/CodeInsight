#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int k,n,dis[maxn];
vector<int> a[maxn];
bool vis[maxn];
int bfs(int st,int nxt){
    queue<int> q;
    for(int i=1;i<=n;i++)
        dis[i]=maxn;
    dis[st]=0;
    dis[nxt]=0;
    q.push(st);
    q.push(nxt);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int i:a[top]){
            if(dis[i]==maxn){
                dis[i]=dis[top]+1;
                q.push(i);
            }
        }
    }
    int ct=0;
    for(int i=1;i<=n;i++){
        if(dis[i]>k/2)ct++;
    }
    return ct;
}

int main(){
    int u,v;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int ans=2010;
    if(k%2){
        for(int i=1;i<=n;i++){
            for(int j:a[i]){
                ans=min(ans,bfs(i,j));
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            ans=min(ans,bfs(i,i));
        }
    }
    printf("%d\n",ans);
}

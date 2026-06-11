#include<bits/stdc++.h>
using namespace std;
#define vn v[now]
#define dn d[now]
#define cn c[now]
int n,m,q;
vector<int> g[100001];
int v[100001],d[100001],c[100001];
bool vis[100001];
int mindis[100001];
int color[100001];
int now;
void dfs(int vv,int dd){
    if(dd<0 || dd<=mindis[vv])
        return;
    mindis[vv]=dd;//还可以走的步数
    //因为最多是di步,从di开始走一步减1，现在leftd就是剩下的步数呀
    //然后，mindis就是这个地方最多剩的步数，如果后一次剩的步数比前一次少
    //那么就肯定走不出这种颜色覆盖的范围，so，综上所述，应该舍掉 
    if(!color[vv])
        color[vv]=cn;
    if(dd==0)
        return;
    for(int i=0;i<g[vv].size();i++)
        dfs(g[vv][i],dd-1);
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin>>q;
    for(int i=0;i<q;i++)
        cin>>v[i]>>d[i]>>c[i];
    memset(mindis,-1,sizeof(mindis));
    for(int i=q-1;i>=0;i--){
        now=i;
        dfs(vn,dn);
    }
    for(int i=1;i<=n;i++)   
        cout<<color[i]<<endl;
    return 0;
}
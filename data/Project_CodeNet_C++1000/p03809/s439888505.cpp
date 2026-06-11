#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,r=-1;
ll a[100005];
vector<int>g[100005];
ll dfs(int v,int p){
    if(g[v].size()==1)return a[v];
    ll s=0,m=0;
    for(int i=0;i<g[v].size();i++){
        int u=g[v][i];
        if(u!=p){
            ll x=dfs(u,v);
            if(x<0)return -1;
            m=max(x,m);
            s+=x;
        }
    }
    ll y;
    if(s>=s-m)y=m;
    else y=(s+1)/2;
    if(y<=a[v]&&a[v]<=s)return 2*a[v]-s;
    else return -1;
}
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",a+i);
    if(n==2){
        if(a[0]==a[1])printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    for(int i=0;i<n&&r<0;i++)if(g[i].size()>1)r=i;
    if(dfs(r,-1)==0)printf("YES\n");
    else printf("NO\n");
}
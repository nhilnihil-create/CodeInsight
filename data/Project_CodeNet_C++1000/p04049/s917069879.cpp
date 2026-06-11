#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
const int maxn=1e4+10;
struct point{
    int u,to,nxt;
}e[maxn],pp[maxn];
int vis[maxn],head[maxn],s,a[2100][2100],tot;
void add(int u,int v){
    e[tot].nxt=head[u];
    e[tot].u=u;
    e[tot].to=v;
    head[u]=tot++;
}
void dfs(int pre,int st,int dis){
    for (int i=head[st];  i;  i=e[i].nxt){
        int to=e[i].to;
        if (to!=pre){
            a[s][to]=a[to][s]=dis;
            dfs(st,to,dis+1);
        }
    }
}
int n,ans=0,k,u,v,w=0;
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1; i<n; i++){
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
        pp[w].u=u;
        pp[w++].to=v;
    }
    for (int i=1; i<=n; i++){
        s=i;
        dfs(0,i,1);
    }
    if (k%2==0){
        int minn=0x3f3f3f3f;
        for (int i=1; i<=n; i++){
            ans=0;
            for (int j=1; j<=n; j++)
                if (j!=i)
                    if (2*a[j][i]>k)
                        ans++;
            minn=min(ans,minn);
        }
        printf("%d\n",minn);
    }else{
        int minn=0x3f3f3f3f;
        k=k/2;
        for (int i=0; i<w; i++){
            ans=0;
            for (int j=1; j<=n; j++)
                if (a[j][pp[i].u]>k&&a[j][pp[i].to]>k) ans++;
            minn=min(ans,minn);
        }
        printf("%d\n",minn);
    }
    return 0;
}
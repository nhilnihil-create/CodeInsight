#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 205 + 10;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

#define dbg(x1) cout<<#x1<<" = "<<(x1)<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<" "<<#x3<<" = "<<(x3)<<endl
int sg[maxn][maxn];
int dfs(int x,int y)
{
   // dbg2(x,y);
    if(sg[x][y]!=-1) return sg[x][y];
    int vis[200];
    for(int i=0;i<=200;i++) vis[i]=0;
    for(int i=2;i<=x;i+=2) vis[dfs(x-i,y+i/2)]=1;
    for(int i=2;i<=y;i+=2) vis[dfs(x+i/2,y-i)]=1;
    for(int i=0;i<=200;i++) if(vis[i]==0) return (sg[x][y]=i);
}
ll abs_(ll x)
{
    if(x<0) return -x;
    return x;
}
int main() {
    //freopen(".in", "r", stdin);
//    memset(sg,-1,sizeof(sg));
//    sg[0][0]=0;
//    sg[0][1]=0;
//    sg[1][0]=0;
//    sg[1][1]=0;
//    dfs(2,2);
//    for(int i=0;i<=10;i++)
//    {
//        for(int j=0;j<=10;j++)
//        {
//            sg[i][j]=dfs(i,j);
//            if(sg[i][j]==0) dbg3(i,j,sg[i][j]);
//        }
//    }
    ll x,y;scanf("%lld%lld",&x,&y);
    if(abs_(x-y)<=1) printf("Brown\n");
    else printf("Alice\n");
    return 0;
}


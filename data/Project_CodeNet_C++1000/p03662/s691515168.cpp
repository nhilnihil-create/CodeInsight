#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define lowbit(x) (x&(-x))
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define MAX 100000000000000000
#define MOD 1000000007
#define PI 3.141592653589793238462
#define INF 1000000000
#define mem(a) (memset(a,0,sizeof(a)))
typedef long long ll;
vector<int>v[100006];
int x,y,n;
int ans[4]={0,0,0};
int vis[100006];
void bfs(int x,int y)
{
    mem(vis);
    vis[x]=1;
    vis[y]=2;
    queue<int>q;
    q.push(x);
    q.push(y);
    while(!q.empty())
    {
        int pos=q.front();
        ans[vis[pos]]++;
        q.pop();
        for(int i=0;i<v[pos].size();i++)
        {
            if(vis[v[pos][i]]) continue;
            vis[v[pos][i]]=vis[pos];
            q.push(v[pos][i]);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        v[y].push_back(x);
        v[x].push_back(y);
    }
    bfs(1,n);
    puts(ans[2]>=ans[1]?"Snuke":"Fennec");
}
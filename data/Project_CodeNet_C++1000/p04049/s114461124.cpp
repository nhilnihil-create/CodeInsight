#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int n,k;
vector<int> al[2005];
int depth[2005];

queue<int> q;

int bfs(int i,int j){
    memset(depth,-1,sizeof(depth));
    depth[i]=0,q.push(i);
    if (j!=-1) depth[j]=0,q.push(j);
    
    int node;
    int res=0;
    while (!q.empty()){
        node=q.front(),q.pop();
        res++;
        if (depth[node]==(k>>1)) continue;
        for (auto &it:al[node]){
            if (depth[it]==-1){
                depth[it]=depth[node]+1;
                q.push(it);
            }
        }
    }
    
    return res;
}
int main(){
    scanf("%d%d",&n,&k);
    int a,b;
    for (int x=1;x<n;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    
    int ans=0;
    if (k&1){
        for (int x=1;x<=n;x++){
            for (auto &it:al[x]){
                ans=max(ans,bfs(x,it));
            }
        }
    }
    else{
        for (int x=1;x<=n;x++){
            ans=max(ans,bfs(x,-1));
        }
    }
    
    printf("%d\n",n-ans);
}
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans=0;

int n,k;
int p[100005];
vector<int> al[100005];

int dfs(int i,int __p){
    int depth=0;
    for (auto &it:al[i]){
        if (it==__p) continue;
        depth=max(depth,dfs(it,i)+1);
    }
    
    if (p[i]!=1 && depth==k-1){
        ans++;
        return -1;
    }
    else return depth;
}

int main(){
    scanf("%d%d",&n,&k);
    for (int x=1;x<=n;x++) scanf("%d",&p[x]);
    
    if (p[1]!=1) p[1]=1,ans++;
    
    for (int x=2;x<=n;x++){
        al[p[x]].push_back(x);
        al[x].push_back(p[x]);
    }
    
    dfs(1,-1);
    
    printf("%d\n",ans);
}
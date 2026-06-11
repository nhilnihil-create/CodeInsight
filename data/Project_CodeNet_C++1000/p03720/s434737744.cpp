#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<cstring>
#define INF 1e9+10
using namespace std;
vector <int>adj[55];
int n,m,a,b;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        printf("%lu\n",adj[i].size());
    }
    
}

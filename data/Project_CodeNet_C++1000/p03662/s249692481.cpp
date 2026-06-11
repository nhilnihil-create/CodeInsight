#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
int n,p[100005],sz[100005];
vector<int>g[100005];
void dfs(int v){
    sz[v]=1;
    for(int i=0;i<g[v].size();i++){
        int u=g[v][i];
        if(u!=p[v]){
            p[u]=v;
            dfs(u);
            sz[v]+=sz[u];
        }
    }
}
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[--a].PB(--b);
        g[b].PB(a);
    }
    p[0]=-1;
    dfs(0);
    int s=0,t=n-1;
    while(p[t]!=0){
        s++;
        t=p[t];
    }
    s/=2;
    t=n-1;
    while(s){
        t=p[t];
        s--;
    }
    if(n-sz[t]<=sz[t])printf("Snuke\n");
    else printf("Fennec\n");
}

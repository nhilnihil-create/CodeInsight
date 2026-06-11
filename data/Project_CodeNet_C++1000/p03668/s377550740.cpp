#include<bits/stdc++.h>

const int maxn=100010;
using namespace std;
vector<int>G[maxn];
int n,m;
int sg[maxn];

void calc(int cur,int pre)
{
    for(int i=0;i<G[cur].size();i++){
        if(G[cur][i]==pre)
            continue;
        calc(G[cur][i],cur);
        sg[cur]^=(sg[G[cur][i]]+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        int from, to;
        scanf("%d %d",&from,&to);
        G[from].push_back(to);
        G[to].push_back(from);
    }
    calc(1,0);
    printf("%s",sg[1]?"Alice":"Bob");
    return 0;
}

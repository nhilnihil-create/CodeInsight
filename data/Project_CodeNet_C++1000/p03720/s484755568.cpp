#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int i,n,m;
vector<int>adj[60];
scanf("%d %d",&n,&m);
while(m--){
    int u,v;
    scanf("%d %d",&u,&v);
    adj[u].push_back(v);
    adj[v].push_back(u);
}
for(i=1;i<=n;++i){
    printf("%d\n",adj[i].size());
}


    return 0;
}

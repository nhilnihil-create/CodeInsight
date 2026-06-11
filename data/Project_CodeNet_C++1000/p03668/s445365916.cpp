#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e5 +100;
vector<int> G[maxn];
int sg[maxn];
void dfs(int x, int fa){
    sg[x] = 0;
    for(auto to : G[x]){
        if(to == fa) continue;
        dfs(to, x);
        sg[x] ^= (sg[to]+1);
    }
}

int main()
{
    int n, x, y;
    cin>>n;
    for(int i = 1; i < n; i++){
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 1);
    if(sg[1]) cout<<"Alice";
    else cout<<"Bob";
}

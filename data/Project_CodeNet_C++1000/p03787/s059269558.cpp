//
//  main.cpp
//  C
//
//  Created by 黄宇凡 on 2017/3/12.
//  Copyright © 2017年 黄宇凡. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 200005;

int n,m;

vector<int> G[maxn];
int deg[maxn];

int col[maxn];
bool vis[maxn];

bool dfs(int u){
    bool flag = true;
    for(auto v : G[u]){
        if(col[v] == col[u]) return false;
        if(col[v] == -1){
            col[v] = 1 ^ col[u];
            flag &= dfs(v);
        }
    }
    return flag;
}

void Dfs(int u){
    vis[u] = true;
    for(auto v : G[u]){
        if(!vis[v])
            Dfs(v);
    }
}


int main(int argc, const char * argv[]) {
    cin >> n >> m;
    memset(deg,0,sizeof(deg));
    memset(vis,false,sizeof(vis));
    memset(col,-1,sizeof(col));
    
    for(int i = 1;i <= m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    
    int q = 0,p = 0;
    int iso = 0;
    
    for(int i = 1;i <= n;i++){
        if(deg[i] == 0) iso++;
        else{
            if(!vis[i]){
                Dfs(i);
                col[i] = 1;
                if(dfs(i)){
                    q++;
                }else p++;
            }
        }
    }
    long long ans = 1LL * iso * iso + iso * 2LL * (n - iso) + 1LL * p * p + 2LL * p * q +  2LL * q * q;
    cout << ans << endl;
    return 0;
}

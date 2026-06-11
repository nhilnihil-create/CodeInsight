#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;
const int maxn = 1e5 + 100;
vector<int> G[maxn];
int deep[maxn], sz[maxn], f[maxn];
deque<int> Q;
void dfs(int x, int fa, int d){
    deep[x] = d;
    sz[x] = 1;
    f[x] = fa;
    for(auto to : G[x]){
        if(to == fa) continue;
        dfs(to, x, d+1);
        sz[x] += sz[to];
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
    dfs(1, 1, 1);
    x = n;
    while(x != 1){
        Q.push_back(x);
        x = f[x];
    }
    Q.push_back(1);
    int ansB = 0, ansW = 0, B = 0, W, temp;
    while(1){
        if(Q.empty()){
            ansB += sz[B]-1-sz[W];
            ansW = sz[W] - ansW;
            if(ansB <= ansW) cout<<"Snuke"<<endl;
            else cout<<"Fennec"<<endl;
            return 0;
        }
        temp = B;
        B = Q.back(); Q.pop_back();
        if(temp != 0) ansB += sz[temp]-sz[B]-1;
        if(Q.empty()) {
            ansB += sz[B]-1-sz[W];
            ansW = sz[W] - ansW;
            if(ansW <= ansB) cout<<"Fennec"<<endl;
            else cout<<"Snuke"<<endl;
            return 0;
        }
        W = Q.front(); Q.pop_front();
        ansW++;
    }
}
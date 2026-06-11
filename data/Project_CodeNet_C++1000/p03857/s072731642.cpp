#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#define ms(x) memset(x, 0, sizeof(x))
#define inf 0x3f3f3f3f
using namespace std;
const int N = 200005;
vector<int >book[N];
int faf[N], fag[N];
int vis[N];
map<int, int>mp;
void init() {
    for(int i=0; i<N; i++) {
        faf[i] = fag[i] = i;
    }
}
int Find(int *f, int x){
    if(f[x] == x) return x;
    else{
        f[x] = Find(f, f[x]);
        return f[x];
    }
}
void Merge(int *f, int x, int y){
    int a = Find(f, x) , b = Find(f, y);
    if(a!=b){
        f[b] = a;
    }
}
int main() {
    int n, k, l;
    while(cin>>n>>k>>l) {
        int u, v;
        init();
        for(int i=0; i<k; i++) {
            scanf("%d%d",&u,&v);
            Merge(faf, u, v);
        }
        for(int i=0;i<l;i++){
            scanf("%d%d",&u,&v);
            Merge(fag, u, v);
        }
        for(int i=1;i<=n;i++){
            book[Find(faf, i)].push_back(i);        //将同一个连通块中的点 集合起来
        }
        for(int i=1;i<=n;i++){
            mp.clear();
            for(int j=0;j<book[i].size();j++){
                mp[Find(fag, book[i][j])]++;        //枚举当前连通块中的点， 记录这个块中的点在另一个块中的父亲的出现次数。
            }
            for(int j=0;j<book[i].size();j++){
                vis[book[i][j]] += mp[Find(fag, book[i][j])];//统计当前连通块中的点在另一个连通块中的父亲的出现次数
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d%c", vis[i],i==n?'\n':' ');
        }
    }
    return 0;
}

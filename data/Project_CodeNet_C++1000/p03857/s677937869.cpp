#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int Max=3e5+100;
int get_root(int *f, int root){
    return f[root]==root?root:f[root]=get_root(f, f[root]);
}
void merge(int *f, int x,int y){
    int i=get_root(f, x);
    int j=get_root(f, y);
    f[i]=j;
}
int f[Max], g[Max];
void init(int n){
    for(int a=0; a<=n; a++)f[a]=a, g[a]=a;
}
int vis[Max], num[Max];
vector<int> vec[Max];
map<int, int>ma;
int main(){
    int n, m, k, u, v;
    scanf("%d%d%d", &n, &m, &k);
    init(n);
    for(int a=0; a<m; a++){
        scanf("%d%d", &u, &v);
        merge(f, u, v);
    }
    for(int a=0; a<k; a++){
        scanf("%d%d", &u, &v);
        merge(g, u, v);
    }
    for(int a=1; a<=n; a++)vec[get_root(f, a)].push_back(a);
    for(int a=0; a<=n; a++){
        ma.clear();
       // memset(num, 0, sizeof(num));
        for(int b=0; b<vec[a].size(); b++){
            ma[get_root(g, vec[a][b])]++;
            //num[get_root(g, vec[a][b])]++;
        }
        for(int b=0; b<vec[a].size(); b++){
            vis[vec[a][b]]+=ma[get_root(g, vec[a][b])];
        }
    }
    for(int a=1; a<=n; a++)printf("%d%c", vis[a], a==n?'\n':' ');
    return  0;
}
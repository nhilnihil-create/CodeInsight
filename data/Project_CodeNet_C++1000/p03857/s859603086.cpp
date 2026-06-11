#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <map>
using namespace std;

const int maxn = 2e5 + 5;

vector<int> G[maxn];
int n, k, l;
int fa[maxn];
int fa1[maxn];
int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

int Find1(int x){
    return x == fa1[x] ? x : fa1[x] = Find1(fa1[x]);
}

map<pair<int, int>, int> mp;

int main(){
    cin >> n >> k >> l;
    for(int i = 1;i <= n;i++){
        fa[i] = i;
        fa1[i] = i;
    }
    for(int i = 1;i <= k;i++){
        int p, q;
        scanf("%d%d", &p, &q);
        int fx = Find(p);
        int fy = Find(q);
        if(fx != fy)
            fa[fx] = fy;
    }
    for(int i = 1;i <= l;i++){
        int p, q;
        scanf("%d%d", &p, &q);
        int fx = Find1(p); 
        int fy = Find1(q);
        if(fx != fy)
            fa1[fx] = fy;
    }
    mp.clear();
    for(int i = 1;i <= n;i++){
        fa[i] = Find(fa[i]);
        fa1[i] = Find1(fa1[i]);
        mp[make_pair(fa[i], fa1[i])]++;
    }
    for(int i = 1;i <= n;i++){
        int res = mp[make_pair(fa[i], fa1[i])];
        printf("%d%c", res, i == n ? '\n' : ' ');
    }
    return 0;
}


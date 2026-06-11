#include <bits/stdc++.h>
using namespace std;
int p[2][200005], rk[2][200005];
unordered_map<int,unordered_map<int,int> > m;
void init(int n){
    for (int i = 0; i < n; i++){
        p[0][i] = p[1][i] = i;
        rk[0][i] = rk[1][i] = 0;
    }
}
int findset(int id, int x){
    return p[id][x] == x ? x : p[id][x] = findset(id,p[id][x]);
}
void unionset(int id ,int x, int y){
    x = findset(id,x), y = findset(id,y);
    if (x == y) return;
    if (rk[id][x] < rk[id][y]){
        p[id][x] = y;
    }
    else{
        p[id][y] = x;
        if (rk[id][x] == rk[id][y]) rk[id][x]++;
    }
}
int main(){
    int n,k,l;
    scanf("%d%d%d",&n,&k,&l);
    init(n);
    for (int i = 0; i < k; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        unionset(0,a,b);
    }
    for (int i = 0; i < l; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        unionset(1,a,b);
    }
    int a[n], b[n];
    for (int i = 0; i < n; i++){
        a[i] = findset(0,i);
        b[i] = findset(1,i);
        m[a[i]][b[i]]++;
    }
    for (int i = 0; i < n; i++){
        printf("%d ",m[a[i]][b[i]]);
    }
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using P = pair<int, int>;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    set<P> g; //辺が2つ（ペア）あるノードで構成されるグラフ
    rep(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--; //indexが0スタートだから
        g.insert({a, b}); //i番目の定期便（ノード）は、aからbに辺を作る
        g.insert({b, a}); //逆もしかり
    }
    for (int i = 1; i < n - 1; i++) { //島1から島Nへ定期便を2つ使って行けるか全探索。島2からスタートしてn-2まで調べる。
        if(g.count({0, i}) && g.count({i, n - 1})) { //もし、グラフの中に頂点0,iとi,n-1の2辺が1以上あれば。
            printf("POSSIBLE\n");
            return 0;
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
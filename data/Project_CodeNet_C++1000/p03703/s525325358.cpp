#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define LC(x) (x << 1)
#define RC(x) (x << 1 | 1)
#define MID(x, y) ((x + y) >> 1)
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 5;
struct node1{
    LL sum, id;
} a[MAXN];
struct node2 {
    LL l, r, sum;
} tree[MAXN * 4];
LL ans, n, k;
bool cmp(node1 a, node1 b){
    return a.sum == b.sum ? a.id < b.id : a.sum < b.sum;
}
inline void pushup(LL p){
    tree[p].sum = tree[LC(p)].sum + tree[RC(p)].sum;
}
inline void build(LL p, LL l, LL r){
    tree[p].l = l;
    tree[p].r = r;
    if (l == r){
        //scanf("%d", &tree[p].sum);
        return;
    }
    build(LC(p), l, MID(l, r));
    build(RC(p), MID(l, r) + 1, r);
    pushup(p);
}
inline void update(LL p, LL id){
    if (tree[p].l == id && tree[p].r == id){
        tree[p].sum++;
        return;
    }
    LL mid = MID(tree[p].l, tree[p].r);
    if (mid >= id)
        update(LC(p), id);
    else
        update(RC(p), id);
    pushup(p);
}
inline void query(int p, int l, int r){
    if (l > tree[p].r || r < tree[p].l)
        return;
    if (l <= tree[p].l && r >= tree[p].r)
    {
        ans += tree[p].sum;
        return;
    }
    query(LC(p), l, r);
    query(RC(p), l, r);
}
int main(){
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++){
        LL x;
        scanf("%lld", &x);
        a[i].id = i;
        a[i].sum = a[i - 1].sum + x - k;
    }
    sort(a + 1, a + n + 1, cmp);
    build(1, 1, n);
    //cout << "ssdfsf" << endl;
    for (int i = 1; i <= n; i++){
        update(1, a[i].id);
        if (a[i].sum >= 0)
            ans++;
        if (a[i].id - 1 == 0)
            continue;
        query(1, 1, a[i].id - 1);
    }
    //cout << "sdfsfs" << endl;
    printf("%lld\n", ans);
    return 0;
}
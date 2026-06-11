#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;

map<int, int> ma;
const int MAXN = 200005, MAXM = 800005;
struct node{
    int l, r;
    ll sum;
}tree[MAXM];
int n, c;
ll ans;
ll a[MAXN], b[MAXN];

void pushup(int q){
    tree[q].sum = tree[q << 1].sum + tree[q << 1 | 1].sum;
}

void build(int q, int l, int r){
    tree[q].l = l;
    tree[q].r = r;
    if(l == r){
        tree[q].sum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(q << 1, l, mid);
    build(q << 1 | 1, mid + 1, r);
    pushup(q);
}

void update(int q, int x, int y){
    if(tree[q].l > x || tree[q].r < x) return;
    if(tree[q].l == x && tree[q].r == x){
        tree[q].sum += y;
        return;
    }
    update(q << 1, x, y);
    update(q << 1 | 1, x, y);
    pushup(q);
}

void query(int q, int l, int r){
    if(tree[q].l > r || tree[q].r < l) return;
    if(tree[q].l >= l && tree[q].r <= r){
        ans += tree[q].sum;
        return;
    }
    query(q << 1, l, r);
    query(q << 1 | 1, l, r);
}

void solve(){
    sort(b, b + n + 1);
    c = unique(b, b + n + 1) - b;
    for (int i = 0; i <= n; i++)
        a[i] = lower_bound(b, b + c + 1, a[i]) - b + 1;
}

int main(){
    int k, m = 0;
    scanf("%d%d", &n, &k);
    ll res = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        a[i] -= k; a[i] += a[i - 1];
        b[i] = a[i];
    }
    solve();
    build(1, 0, n);
    for(int i = 0; i <= n; i++){
        ans = 0;
        query(1, 0, a[i]);
        res += ans;
        update(1, a[i], 1);
    }
    printf("%lld\n", res);
    return 0;
}
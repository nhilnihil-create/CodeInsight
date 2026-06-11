// #include <cstdio>
// #include <algorithm>
// #define N 100001
// using namespace std;
// int n, m;
// struct souvenir
// {
//     int l, r, len;
//     bool operator<(const souvenir &b)
//     {
//         return len < b.len;
//     }
// } s[N * 3];
// int c[N];
// int get(int i)
// {
//     int ans = 0;
//     for (; i; i -= i & (-i))
//         ans += c[i];
//     return ans;
// }
// void add(int i, int v)
// {
//     for (; i <= m; i += i & (-i))
//         c[i] += v;
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     for (int i = 1, l, r; i <= n; ++i)
//     {
//         scanf("%d%d", &l, &r);
//         s[i] = (souvenir){l, r, r - l + 1};
//     }
//     sort(s + 1, s + 1 + n);
//     for (int i = 1, j = 1; i <= m; ++i)
//     {
//         while (j <= n && s[j].len < i)
//         {
//             add(s[j].l, 1);
//             add(s[j].r + 1, -1);
//             ++j;
//         }
//         int ans = n - j + 1;
//         for (int k = i; k <= m; k += i)
//             ans += get(k);
//         printf("%d\n", ans);
//     }
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
// typedef long long LL; //多次踩坑之后已经可以放心使用
const int MAXN = 1e5 + 5;
namespace Segtree
{
    struct node
    {
        int l, r;
        int sum, lazy;
    } tree[MAXN << 2];
    int a[MAXN]; //you can put the num to this first
    inline void push_down(int);
    inline void build(int i, int l, int r)
    {
        tree[i].l = l;
        tree[i].r = r;
        tree[i].lazy = 0;
        if (l == r)
        {
            tree[i].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
    }
    inline void add(int i, int l, int r, int k)
    {
        if (tree[i].l >= l && tree[i].r <= r)
        {
            tree[i].sum += k * (tree[i].r - tree[i].l + 1);
            tree[i].lazy += k;
            return;
        }
        if (tree[i].r < l || tree[i].l > r)
            return;
        push_down(i);
        if (tree[i * 2].r >= l)
            add(i * 2, l, r, k);
        if (tree[i * 2 + 1].l <= r)
            add(i * 2 + 1, l, r, k);
        tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
    }
    inline void push_down(int i)
    {
        if (tree[i].lazy != 0)
        {
            tree[i * 2].lazy += tree[i].lazy;
            tree[i * 2 + 1].lazy += tree[i].lazy;
            int mid = (tree[i].l + tree[i].r) >> 1;
            tree[i * 2].sum += tree[i].lazy * (mid - tree[i * 2].l + 1);
            tree[i * 2 + 1].sum += tree[i].lazy * (tree[i * 2 + 1].r - mid);
            tree[i].lazy = 0;
        }
    }
    inline int search(int i, int l, int r)
    {
        if (tree[i].l >= l && tree[i].r <= r)
        {
            return tree[i].sum;
        }
        if (tree[i].r < l || tree[i].l > r)
            return 0;
        push_down(i);
        int ans = 0;
        if (tree[i * 2].r >= l)
            ans += search(i * 2, l, r);
        if (tree[i * 2 + 1].l <= r)
            ans += search(i * 2 + 1, l, r);
        return ans;
    }
} // namespace Segtree
struct Node
{
    int l, r, len;
} node[MAXN * 3];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Segtree::build(1, 1, m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &node[i].l, &node[i].r);
        node[i].len =  node[i].r - node[i].l + 1;
    }
    sort(node + 1, node + n + 1, [&](Node a, Node b){
        return a.len < b.len;
    });
    int cntnode = 1;
    for (int d = 1; d <= m; d++)
    {
        while (cntnode <= n && node[cntnode].len < d)
        {
            Segtree::add(1, node[cntnode].l, node[cntnode].r, 1);
            cntnode++;
        }
        int ans = n - cntnode + 1;
        for (int k = d; k <= m; k += d)
            ans += Segtree::search(1, k, k);
        printf("%d\n", ans);
    }
    // int T;
    // cin >> T;
}
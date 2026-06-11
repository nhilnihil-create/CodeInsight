#include<bits/stdc++.h>
#define reg register
#define maxn 300001 
using namespace std;
inline int  read() {
    reg int s = 0, t = 0; reg char ch = getchar();
    while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return t ? -s : s;
}
int n, m, cnt, ls[maxn * 21], now, d[maxn], rs[maxn * 21], ans, sum[maxn * 20], root[maxn];
struct node{int l, r;} a[400001];
bool cmp(node g, node h){
    if(g.l != h.l) return g.l < h.l;
    else return g.r < h.r;
}
int build(int l, int r){
    int num = ++cnt;
    int mid = l + r >> 1;
    if(l != r){
        build(l, mid); build(mid + 1, r);
    }
    return num;
}
int update(int pre, int l, int r, int pos){
    int num = ++ cnt; 
    sum[num] = sum[pre] + 1; ls[num] = ls[pre], rs[num] = rs[pre];
    if(l != r){ 
         int mid = l + r >> 1;
        if(pos <= mid) ls[num] = update(ls[pre], l, mid, pos);
        else rs[num] = update(rs[pre], mid + 1, r, pos);
    }
    return num;
}
int query(int now, int pre, int l, int r, int pos){
    if(l > pos) return 0;
    int res = 0;
    if(r <= pos){
        res += sum[now] - sum[pre]; 
        return res;
    }
    int mid = l + r >> 1;
    res += query(ls[now], ls[pre], l, mid, pos);
    if(pos > mid) res += query(rs[now], rs[pre], mid + 1, r, pos);
    return res;
}
int main()
{
    n = read(); m = read();
    for(int i = 1; i <= n; i++)
        a[i].l = read(), a[i].r = read();
    sort(a + 1, a + n + 1, cmp);
    root[0] = build(1, m); now = 1;
     for(int i = 1; i <= m; i++){
        int t = root[i - 1];
        while(a[now].l == i){
            t = update(t, 1, m, a[now].r); now++;
        }
        root[i] = t;
    }
    for(int i = 1; i <= n; i++) d[a[i].l]++;
    for(int i = 1; i <= m; i++) d[i] += d[i - 1];
    for(int i = 1; i <= m; i++){
        ans = 0;
        for(int j = i; j <= m; j += i){
            ans += d[j] - d[j - i];
            ans -= query(root[j], root[j - i], 1, m, j - 1);
        } 
        printf("%d\n",ans);
    }
}
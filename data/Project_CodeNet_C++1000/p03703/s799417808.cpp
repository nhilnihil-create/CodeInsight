// 解き直し.
// https://img.atcoder.jp/arc075/editorial.pdf
// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define a first
#define b second
#define all(x) x.begin(), x.end()
LL a[202020], aCum[202020], b[202020], c[202020];

// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template<typename T>
struct BIT{
    int n;
    vector<T> d;
    BIT(int n = 0) : n(n), d(n + 1) {}
    void add(int i, T x = 1){
        for(i++; i <= n; i += i & -i) d[i] += x;
    }
    T sum(int i){
        T x = 0;
        for(i++; i; i -= i & -i) x += d[i];
        return x;
    }
    T sum(int l, int r){
        return sum(r - 1) - sum(l - 1);
    }
};

int main(){
    
    // 1. 入力情報.
    int N;
    LL K;
    scanf("%d %lld", &N, &K);
    rep(i, N) scanf("%lld", &a[i]);
    
    // 2. 累積和.
    rep(i, N) aCum[i + 1] = aCum[i] + a[i];
    
    // 3. 数列 b を 計算.
    rep(j, N) b[j + 1] = aCum[j + 1] - (LL)(j + 1) * K;
    // rep(j, N + 1) printf("%lld ", b[j]);
    // puts("");
    
    // 4. 大小関係を保ったまま, 0 ～ N に 圧縮.
    // -> p.a: 圧縮前の値(b[0] ～ b[N]), p.b: 圧縮後の値(0 ～ N).
    map<LL, int> m;
    rep(j, N + 1) m[b[j]] = 1;
    int idx = -1;
    for(auto &p : m) p.b = ++idx;
    // for(auto &p : m) printf("a=%lld b=%d\n", p.a, p.b);
    rep(j, N + 1) c[j] = m[b[j]];
    
    // 5. 0 ～ N の 出現回数 を 保持しながら, 集計.
    BIT<LL> ft(N + 1);
    LL ans = 0;
    rep(j, N + 1){
        // c[j]以下 の 値が, c[0] ～ c[j - 1] で 何回出現したかを集計.
        ans += ft.sum(0, c[j] + 1);
        
        // c[j] を 反映.
        ft.add(c[j], 1);
    }
    
    // 6. 出力.
    printf("%lld\n", ans);
    return 0;
    
}
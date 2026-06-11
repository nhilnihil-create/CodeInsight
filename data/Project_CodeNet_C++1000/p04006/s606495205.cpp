#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define y1 abcde
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>
#define int long long

const ll inf = 2e15;
const int N = 2e3 + 15;
const int L = 15;
int n, x, a[N], ans = inf, LG[N], st[L][N];

inline void build() {
    for(int i = 2; i < N; ++i)
        LG[i] = LG[i >> 1] + 1;
    for(int i = 1; i <= n; ++i)
        st[0][i] = a[i];
    for(int j = 1; j < L; ++j)
        for(int i = 1; i <= n; ++i)
            st[j][i] = min(st[j-1][i], st[j-1][min(n, i + (1 << (j - 1)))]);
}

inline int get(int l, int r) {
    int lg = LG[r - l + 1];
    return min(st[lg][l], st[lg][r - (1 << lg) + 1]);
}

main() {
    cin >> n >> x;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    reverse(a + 1, a + 1 + n);
    build();
    for(int shift = 0; shift < n; ++shift) {
        int cur = 0;
        for(int i = 1; i <= n; ++i) {
            int ind = i + shift;
            if(ind > n)
                cur += min(get(i, min(n, ind)), get(1, ind - n));
            else
                cur += get(i, min(n, ind));
        }
        cur += shift * x;
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
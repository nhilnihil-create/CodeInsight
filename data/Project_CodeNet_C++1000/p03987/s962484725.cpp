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

const int inf = 2e9;
const int N = 2e5 + 15;
int n, a[N], l[N], r[N];
int st[N], stsz, ans;

inline int st_last() {
    return st[stsz - 1];
}

main() {
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        while(stsz && a[st_last()] > a[i])
            stsz--;
        if(stsz)
            l[i] = st_last() + 1;
        else
            l[i] = 1;
        st[stsz++] = i;
    }
    stsz = 0;
    for(int i = n; i; --i) {
        while(stsz && a[st_last()] > a[i])
            stsz--;
        if(stsz)
            r[i] = st_last() - 1;
        else
            r[i] = n;
        st[stsz++] = i;
    }
    for(int i = 1; i <= n; ++i)
        ans += a[i] * ((i - l[i] + 1) * (r[i] - i + 1));
    cout << ans << endl;
    return 0;
}
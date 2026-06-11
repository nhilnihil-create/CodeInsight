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

const int inf = 2e9;
const int N = 1e2 + 15;
int n, m, a[N], b[N], dist, ord[N], d[N][N];
bool used[N];

main() {
    memset(d, 0x3f, sizeof(d));
    scanf("%d\n", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ord[i] = i;
        d[i][i] = 0;
    }
    sort(ord + 1, ord + 1 + n, [&](int x, int y) {
        return a[x] < a[y];
    });
    b[1] = ord[n];
    dist = a[ord[n-1]] + 1;
    b[dist] = ord[n-1];
    used[b[1]] = used[b[dist]] = true;
    for(int i = 1; i <= n; ++i)
        if(!used[i])
            for(int j = 2; j < dist; ++j)
                if(!b[j] && max(j - 1, dist - j) == a[i]) {
                    used[i] = true;
                    b[j] = i;
                    break;
                }
    for(int i = 1; i <= n; ++i)
        if(!used[ord[i]])
            for(int j = 2; j < dist; ++j)
                if(max(j - 1, dist - j) + 1 == a[ord[i]]) {
                    used[ord[i]] = true;
                    d[b[j]][ord[i]] = d[ord[i]][b[j]] = 1;
                    break;
                }
    for(int i = 1; i <= dist; ++i)
        if(!b[i])
            return cout << "Impossible" << endl, 0;
    for(int i = 2; i <= dist; ++i)
        d[b[i]][b[i-1]] = d[b[i-1]][b[i]] = 1;
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for(int i = 1; i <= n; ++i)
        if(a[i] != *max_element(d[i] + 1, d[i] + 1 + n))
            return cout << "Impossible" << endl, 0;
    cout << "Possible" << endl;
    return 0;
}
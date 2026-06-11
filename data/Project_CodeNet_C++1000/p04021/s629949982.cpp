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
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>
#define int long long

const int inf = 2e9;
const int N = 2e5 + 15;
int n, a[N], ans, x[2];
bool used[N];
vector <int> cur;

main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        cur.pb(a[i]);
    }
    sort(cur.begin(), cur.end());
    for(int i = 1; i <= n; ++i)
        a[i] = lower_bound(cur.begin(), cur.end(), a[i]) - cur.begin() + 1;
    for(int i = 1; i <= n; ++i) {
        if(a[i] % 2 != i % 2)
            ++x[a[i] & 1];
    }
    cout << max(x[0], x[1]) << endl;
    return 0;
}
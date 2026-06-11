#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <random>
#include <iomanip>
#include <bitset>
 
 
using namespace std;
 
template<typename T> void uin(T &a, T b) {
    if (b < a) {
        a = b;
    }
}
 
template<typename T> void uax(T &a, T b) {
    if (b > a) {
        a = b;
    }
}
#define int long long
#define left left228
#define right right228
#define prev prev228
#define mp make_pair
#define all(v) v.begin(), v.end()
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define x first
#define y second

const int N = 200 * 1000 + 228;

int n;
int a[N], l[N], r[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        l[i] = 0, r[i] = n + 1;
    }
    vector<int> st;
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && a[i] < a[st.back()]) {
            r[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for (int i = n; i; --i) {
        while (!st.empty() && a[i] < a[st.back()]) {
            l[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += a[i] * (i - l[i]) * (r[i] - i);
    }
    cout << res << '\n';
    return 0;
}
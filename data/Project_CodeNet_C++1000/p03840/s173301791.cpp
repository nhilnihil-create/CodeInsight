#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
const int mod = 1e9 + 7;
const int N = 2e5 + 15;
int I, O, T, J, L, S, Z, ans;

inline int gt(int x) {
    return x - (x & 1);
}

main() {
    cin >> I >> O >> T >> J >> L >> S >> Z;
    int is = (I % 2) + (L % 2) + (J % 2);
    if(is >= 2 && I && L && J) {
        ans += 3;
        --I, --L, --J;
    }
    ans += gt(I) + gt(J) + gt(L) + O;
    cout << ans << endl;
    return 0;
}
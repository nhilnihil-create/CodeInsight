/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
signed main() {
    int k;
    cin >> k;
    int n = 50;

    int ans[n];
    for (int i = 0; i < n; i++) {
        ans[i] = (n - 1) + k / n;
    }

    int remain = k % n;
    for (int i = 0; i < remain; i++) {
        ans[i] += n;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ans[j]--;
        }
    }

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
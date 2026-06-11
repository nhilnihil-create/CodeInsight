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
    int N, T;
    cin >> N >> T;

    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    int M[N];
    fill(M, M + N, 0);

    int mx = 0;
    for (int i = N - 1; i >= 0; i--) {
        M[i] = mx;
        mx = max(mx, A[i]);
    }

    map<int, int> m;
    map<int, int> :: iterator it;

    for (int i = 0; i < N; i++) {
        if (M[i] < A[i]) continue;
        m[M[i] - A[i]]++;
    }

    int max_cnt = -1;
    int max_val = -1;
    for (it = m.begin(); it != m.end(); it++) {
        if (it->first > max_val) {
            max_val = it->first;
            max_cnt = it->second;
        }
    }

    cout << max_cnt << endl;

    return 0;
}
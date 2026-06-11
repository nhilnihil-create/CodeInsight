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
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
signed main() {
    int N;
    cin >> N;
    int A[N];
    int total = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        total += A[i];
    }

    if (total % (N * (N + 1) / 2) != 0) {
        cout << "NO" << endl;
        return 0;
    }

    int k = total / (N * (N + 1) / 2);
    int fall_sum = 0;

    for (int i = 0; i < N; i++) {
        int now_idx = i;
        int next_idx = i + 1;

        if (i == N - 1) {
            next_idx = 0;
        }

        if (A[next_idx] - A[now_idx] == k) continue;
        if (A[next_idx] - A[now_idx] > k) {
            cout << "NO" << endl;
            return 0;
        }

        int fall = (A[now_idx] + k) - A[next_idx];

        if (fall % N != 0) {
            cout << "NO" << endl;
            return 0;
        }

        fall_sum += fall / N;
    }

    if (fall_sum == k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
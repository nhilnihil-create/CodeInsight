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
    int H, W, N;
    cin >> H >> W >> N;

    int cnt[10];
    fill(cnt, cnt + 10, 0);
    cnt[0] = (H - 2) * (W - 2);

    map<P, bool> m;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int center_i = a + i;
                int center_j = b + j;
                if (center_i <= 0 || center_i >= H - 1 || center_j <= 0 || center_j >= W - 1) continue;

                int black_cnt = 0;
                for (int p = -1; p <= 1; p++) {
                    for (int q = -1; q <= 1; q++) {
                        if (m.find(make_pair(center_i + p, center_j + q)) != m.end()) black_cnt++;
                    }
                }

                cnt[black_cnt]--;
                cnt[black_cnt+1]++;
            }
        }

        m[make_pair(a, b)] = true;
    }

    for (int i = 0; i < 10; i++) cout << cnt[i] << endl;

    return 0;
}
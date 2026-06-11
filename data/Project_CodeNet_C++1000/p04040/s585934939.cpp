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
class Combination {
    int powmod(int a, int p) {
        int ans = 1;
        int mul = a;

        for (; p > 0; p >>= 1, mul = (mul * mul) % mod) {
            if ((p & 1) == 1) ans = (ans * mul) % mod;
        }

        return ans;
    }
public:
    int N;
    int mod;
    vector<int> fact;
    vector<int> revFact;

    Combination(int n, int m) : N(n), mod(m), fact(n+1), revFact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i-1] * i;
            fact[i] %= mod;
        }

        // Fermat's little theorem
        revFact[N] = powmod(fact[N], mod - 2);

        for (int i = N-1; i >= 0; i--) {
            revFact[i] = revFact[i+1] * (i+1);
            revFact[i] %= mod;
        }
    }

    int get(int a, int b) {
        return (((fact[a] * revFact[b]) % mod) * revFact[a-b]) % mod;
    }
};

signed main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    int ret = 0;
    Combination comb = Combination(H + W, MOD);

    for (int i = 0; i <= H - A - 1; i++) {
        ret += comb.get(i + B - 1, i) * comb.get((H - 1 - i) + (W - 1 - B), H - 1 - i);
        ret %= MOD;
    }

    cout << ret << endl;

    return 0;
}
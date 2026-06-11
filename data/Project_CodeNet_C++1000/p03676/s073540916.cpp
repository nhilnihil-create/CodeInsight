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
        if (a < 0 || b < 0) return 0;
        if (b > a) return 0;
        return (((fact[a] * revFact[b]) % mod) * revFact[a-b]) % mod;
    }
};

signed main() {
    int n;
    cin >> n;

    int A[n+1];
    map<int, int> m;
    int dup = -1;
    for (int i = 0; i < n + 1; i++) {
        cin >> A[i];
        m[A[i]]++;
        if (m[A[i]] == 2) dup = A[i];
    }

    int left_idx = -1;
    int right_idx = -1;
    for (int i = 0; i < n + 1; i++) {
        if (A[i] == dup) {
            if (left_idx == -1) {
                left_idx = i;
            } else {
                right_idx = i;
            }
        }
    }

    int mid = right_idx - left_idx - 1;
    int right = n - right_idx;
    int left = left_idx;
    int side = right + left;
    Combination comb = Combination(n, MOD);

    for (int k = 1; k <= n + 1; k++) {
        int ret = 0;

        if (n - 1 >= k) {
            ret += comb.get(n - 1, k);
            ret %= MOD;
        }

        if (n >= k) {
            ret += 2 * comb.get(n - 1, k - 1);
            ret %= MOD;
        }


        if (side >= k - 1) {
            ret -= comb.get(side, k - 1);
            ret += MOD;
            ret %= MOD;
        }

        if (k >= 2) {
            ret += comb.get(n - 1, k - 2);
            ret %= MOD;
        }

        cout << ret << endl;
    }

    return 0;
}
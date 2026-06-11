/// Containers Start
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
/// C Header Files
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <math.h>
#include <stdio.h>
/// Containers End

using namespace std;

/// Math Start
#define PI acos(-1.0)
#define Pi 3.141592653589793
#define EPS (1e-7)
#define INF (0x3f3f3f3f)
/// Math End

/// Extra Start
#define nn '\n'
#define pb push_back
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
#define sz(a) int((a).size())
#define space " "
#define All(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
/// Extra End

#define rep(i, n) for (int i = 0; i < n; i++)
#define Cini(a)                                                                \
    int a;                                                                     \
    cin >> a;
#define Cinii(a, b)                                                            \
    int a, b;                                                                  \
    cin >> a >> b;
#define Ciniii(a, b, c)                                                        \
    int a, b, c;                                                               \
    cin >> a >> b >> c;
#define Cins(s)                                                                \
    string s;                                                                  \
    cin >> s;
#define Cinss(s1, s2)                                                          \
    string s1, s2;                                                             \
    cin >> s1 >> s2;
#define Cinc(c)                                                                \
    char c;                                                                    \
    cin >> c;
/// Functions End

/// Graph Start
struct edge {
    int from, to;
    long long cost;
};
/// Graph End

/// Debug Start
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl;
#define deb3(x, y, z)                                                          \
    cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": "   \
         << z << endl;
/// Debug End

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

/**>>>>>>>>>>>>>>>>>>> END <<<<<<<<<<<<<<<<<<**/

/// template

#define int long long

class Combination {
    int powmod(int a, int p) {
        int ans = 1;
        int mul = a;

        for (; p > 0; p >>= 1, mul = (mul * mul) % mod) {
            if ((p & 1) == 1)
                ans = (ans * mul) % mod;
        }

        return ans;
    }

  public:
    int N;
    int mod;
    vector<int> fact;
    vector<int> revFact;

    Combination(int n, int m) : N(n), mod(m), fact(n + 1), revFact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i;
            fact[i] %= mod;
        }

        // Fermat's little theorem
        revFact[N] = powmod(fact[N], mod - 2);

        for (int i = N - 1; i >= 0; i--) {
            revFact[i] = revFact[i + 1] * (i + 1);
            revFact[i] %= mod;
        }
    }

    int get(int a, int b) {
        return (((fact[a] * revFact[b]) % mod) * revFact[a - b]) % mod;
    }
};

signed main(void) {
    cin.sync_with_stdio(false);
    cin.tie(0);
    Cinii(H, W);
    Cinii(A, B);
    H--; W--; A--; B--;
    Combination com = Combination(H + W, MOD);
    ll ans = 0;
    ans += com.get(H+ W , H);
    rep(i, B+1) {
        (ans += (MOD - (com.get(H - A - 1 + i, i) * com.get(A + W - i , W - i))%MOD))%=MOD;
        // deb3(i, com.get(H - A - 1 + i, i), com.get(A + W - i, W - i));
    }
    cout << ans << nn;
    return 0;
}
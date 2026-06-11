#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

const int COMB_MAX = 510000;
ll fac[COMB_MAX], finv[COMB_MAX], inv[COMB_MAX];

ll comb(ll a, ll b)
{
    if (a < b)
        return 0;
    if (a < 0 || b < 0)
        return 0;

    return fac[a] * (finv[b] * finv[a - b] % MOD) % MOD;
}

void combInit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < COMB_MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    combInit();

    ll h, w, a, b, ans;
    cin >> h >> w >> a >> b;

    ans = 0;

    for (ll i = 1; i <= h - a; i++)
    {
        ans += comb(b - 1 + i - 1, min(b - 1, i - 1)) * comb(h - i + w - b - 1, min(h - i, w - b - 1));
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
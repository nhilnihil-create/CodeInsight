#include <bits/stdc++.h>

using namespace std;
using llong = long long int;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const int MOD = 1000000007;
const int INF = 1000000000;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const int MAX = 200101;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

template <class Abel>
struct BinaryIndexTree
{
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0; // to be set

    /* [1, n] */
    BinaryIndexTree(int n) { init(n); }
    void init(int n)
    {
        for (int iter = 0; iter < 2; ++iter)
            dat[iter].assign(n + 1, UNITY_SUM);
    }

    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(int p, int a, Abel x)
    {
        for (int i = a; i < (int)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, Abel x)
    {
        sub_add(0, a, x * -(a - 1));
        sub_add(1, a, x);
        sub_add(0, b, x * (b - 1));
        sub_add(1, b, x * (-1));
    }

    /* a is 1-indexed, [a, b) */
    inline Abel sub_sum(int p, int a)
    {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[p][i];
        return res;
    }

    inline Abel sum(int a, int b)
    {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }

    /* debug */
    void print()
    {
        for (int i = 1; i < (int)dat[0].size(); ++i)
            cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

//////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[]) {
    cin.tie(0); 
    ios::sync_with_stdio(false);
    // for file input
    /* ifstream in("input.txt");
    ifstream in("input.txt"); */

    int n;
    cin >> n;
    llong k;
    cin >> k;
    vector<llong> A(n);
    rep(i, n) cin >> A[i];

    vector<llong> cumA(n + 1);
    cumA[0] = 0;
    rep(i, n) cumA[i + 1] = cumA[i] + A[i] - k;
    
    vector<llong> zaatsu = cumA;
    sort(all(zaatsu));
    zaatsu.erase(unique(all(zaatsu)), zaatsu.end());

    BinaryIndexTree<llong> BIT(n + 10);
    llong ans = 0;
    rep(i, n + 1) {
        int idx = lower_bound(all(zaatsu), cumA[i]) - zaatsu.begin();
        ans += BIT.sum(1, idx + 2);
        BIT.add(idx + 1, idx + 2, 1);
    }

    cout << ans << endl;

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////
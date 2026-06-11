// 　　＿＿
// 　／　<＠ﾌ
//  ｜(ﾉﾉハ))
//  ﾉ从ﾟヮﾟ从
// 　ﾉ｜ｿﾉГ|つ author:hotarunx
// 〈_ﾉ^^^ヽ|
// 　~~tｧtｧ~
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

class Combination {
   private:
    long long maxn;
    long long mod;
    vector<long long> fact, rev_fact;

   public:
    // コンストラクタ。maxn: 組み合わせのnの最大値。m: mod
    Combination(long long maxn, long long mod) : maxn(maxn), mod(mod) {
        setFact(maxn);
    }

    // 1からnの階乗とその逆元を前計算
    void setFact(long long n) {
        fact.resize(n + 1);
        rev_fact.resize(n + 1);
        fact[0] = 1;
        for (long long i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            fact[i] %= mod;
        }
        rev_fact[n] = modpow(fact[n], mod - 2, mod);
        for (long long i = n - 1; i >= 0; i--) {
            rev_fact[i] = rev_fact[i + 1] * (i + 1);
            rev_fact[i] %= mod;
        }
    }

    constexpr long long modpow(long long a, long long n, long long m) {
        long long rtn = 1;
        while (n > 0) {
            if (n & 1) rtn = rtn * a % m;
            a = a * a % m;
            n >>= 1;
        }
        return rtn;
    }

    // n種類のものからk個選ぶ場合の数
    long long c(long long n, long long k) {
        if (!(0 <= n && n <= maxn) || !(0 <= k && k <= maxn)) return -1;
        return (((fact[n] * rev_fact[k]) % mod) * rev_fact[n - k]) % mod;
    }

    // n種類のものから重複を許してk個選ぶ場合の数
    // n+k-1<=maxn とすること
    long long h(long long n, long long k) { return c(n + k - 1, k); }

    // n種類のものからk個選んで並び替える場合の数
    long long p(long long n, long long k) {
        if (!(0 <= n && n <= maxn) || !(0 <= k && k <= maxn)) return -1;
        return fact[n] * rev_fact[n - k] % mod;
    }
};

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int p;
    cin >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int evens = 0, odds = 0;

    for (auto &&i : a) {
        if (i % 2)
            odds++;
        else
            evens++;
    }

    Combination c(100, 1000000007);

    // 食べるビスケットの枚数を2で割ると余りが1に等しくなる
    // → 奇数枚の袋を奇数個食べた
    // 食べるビスケットの枚数を2で割ると余りが0に等しくなる
    // → 奇数枚の袋を偶数個食べた

    // 偶数枚の袋はどのように食べてもいい

    // 条件を満たすように奇数枚の袋と、偶数枚の袋を選んで食べる場合の数を求める
    // 両方をかける

    int even_ways = 0, odd_ways = 0;

    // p=1のとき、odd_ways は n個の袋から1個を選ぶ+n個の袋から3個を選ぶ+...
    // p=0はにたような感じで
    // つまり
    // odd_ways = Σ nCi (if i%2==p) (nは奇数枚の袋の数)
    for (int i = 0; i <= odds; i++) {
        if (i % 2 == p) {
            odd_ways += c.c(odds, i);
        }
    }

    // 偶数枚の袋を選ぶ場合の数は 2^(evens)
    even_ways = pow(2, evens);

    const int ans = even_ways * odd_ways;

    cout << ans << endl;
}

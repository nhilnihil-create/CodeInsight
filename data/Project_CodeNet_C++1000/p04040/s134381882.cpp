#include <bits/stdc++.h>
#define MAX_H 100000
#define MAX_W 100000
#define BASE 1000000007
using namespace std;

long fact_memo[MAX_H + MAX_W + 1];
unordered_map<long, long> inv_memo;

void init(long h, long w) {
    fact_memo[0] = 1;
    fill(fact_memo + 1, fact_memo + h + w + 1, 0);
}

long mod_pow(long x, long k) {
    long ret = 1;
    while (k > 0) {
        if (k & 1)
            ret = (ret * x) % BASE;
        x = (x * x) % BASE;
        k >>= 1;
    }
    return ret;
}

long mod_inv(long x) {
    if (inv_memo.find(x) != inv_memo.end())
        return inv_memo[x];
    return inv_memo[x] = mod_pow(x, BASE - 2);
}

long mod_fact(long x) {
    if (fact_memo[x] > 0)
        return fact_memo[x];
    return fact_memo[x] = (x * mod_fact(x - 1)) % BASE;
}

long mod_combi(long n, long r) {
    long ret = (((mod_fact(n) * mod_inv(mod_fact(r))) % BASE) * mod_inv(mod_fact(n - r))) % BASE;
    return ret;
}

int main() {
    long h, w, a, b;
    cin >> h >> w >> a >> b;
    init(h, w);
    long ans = 0;
    for (long i = 0; i < h - a; i++) {
        ans = (ans + (mod_combi(b + i - 1, i) * mod_combi(w - b + h - i - 2, h - i - 1)) % BASE) % BASE;
    }
    cout << ans << endl;
    return 0;
}

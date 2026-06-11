#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

vector<bool> ng;
bool check(int k) {
    while (k) {
        if (ng[k % 10]) return false;
        k /= 10;
    }
    return true;
}

void solve(long long N, long long K, std::vector<long long> D) {
    ng = vector<bool>(10);
    rep (i, K) ng[D[i]] = 1;
    loop (i, N, 100000) if (check(i)) {
        cout << i << endl;
        break;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> D(K);
    for (int i = 0; i < K; i++) {
        scanf("%lld", &D[i]);
    }
    solve(N, K, std::move(D));
    return 0;
}

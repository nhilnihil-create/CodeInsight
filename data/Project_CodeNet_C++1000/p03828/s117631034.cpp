#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1000000007;
vector<int> cnt(1001, 0);

void prime_factorize(long long N) {
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        cnt[a] += ex;
    }
    if (N != 1) ++cnt[N];
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) prime_factorize(i);
    ll ans = 1;
    for (int i = 2; i <= N; ++i) {
        if (cnt[i]) ans = (ans * (cnt[i] + 1)) % mod;
    }
    cout << ans << endl;
}
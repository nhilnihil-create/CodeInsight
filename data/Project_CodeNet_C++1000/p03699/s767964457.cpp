#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::vector<long long> s) {
    sort(s.begin(), s.end());
    ll sum = accumulate(s.begin(), s.end(), 0LL);
    if (sum % 10 == 0) {
        rep(i, N) {
            if (s[i] % 10 != 0) {
                sum -= s[i];
                cout << sum << endl;
                return;
            }
        }
        cout << 0 << endl;
        return;
    } else {
        cout << sum << endl;
        return;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> s(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &s[i]);
    }
    solve(N, std::move(s));
    return 0;
}

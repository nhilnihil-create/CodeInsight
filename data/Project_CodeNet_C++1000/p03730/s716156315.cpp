#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const long long MOD = 5;
const string YES = "YES";
const string NO = "NO";

void solve(long long A, long long B, long long C) {
    ll tmp = 0;
    rep(i, 100) {
        tmp += A % B;
        tmp %= B;
        if (tmp == C) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

int main() {
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    long long C;
    scanf("%lld", &C);
    solve(A, B, C);
    return 0;
}

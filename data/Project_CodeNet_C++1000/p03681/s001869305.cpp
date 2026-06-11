#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sizeOf(A) (sizeof(A))/(sizeof(A[0]))
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
const ll MOD = 1e9 + 7;


int main() {
    fastio;

    int n, m;
    cin >> n >> m;
    ll answer = 1;
    if (abs(n-m) >= 2) {
        answer = 0;
    } else if (abs(n-m) == 1) {
        FOR(i, 1, n+1) {
            answer *= i % MOD;
            answer %= MOD;
        }
        FOR(i, 1, m+1) {
            answer *= i % MOD;
            answer %= MOD;
        }
    } else {
        FOR(i, 1, n+1) {
            answer *= i % MOD;
            answer %= MOD;
        }
        FOR(i, 1, m+1) {
            answer *= i % MOD;
            answer %= MOD;
        }
        answer *= 2;
    }

    cout << answer % MOD << "\n";
    return 0;
}

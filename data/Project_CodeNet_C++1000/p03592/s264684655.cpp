#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    bool ans = false;
    rep(i, M+1) {
        rep(j, N+1) {
            if (i*N+j*M-2*i*j == K) {
                ans = true;
                break;
            }
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
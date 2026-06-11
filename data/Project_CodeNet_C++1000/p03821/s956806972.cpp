#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    int N;
    cin >> N;
    deque<ll> A;
    deque<ll> B;
    ll count = 0;
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }
    for (int i = N-1; i >= 0; i--) {
        A[i] += count;
        if (A[i] % B[i] != 0) {
            count += (B[i] - (A[i] % B[i]));
        }
    }
    cout << count << endl;
}
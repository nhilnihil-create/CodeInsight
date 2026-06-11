#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << ": " << x << endl;
#define popcnt __builtin_popcount

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    A[N] = A[0];


    if (accumulate(A.begin(), A.end() - 1, 0LL) % (((N + 1) * N) / 2) != 0) {
        puts("NO");
        return 0;
    }

    ll q = accumulate(A.begin(), A.end() - 1, 0LL) / (((N + 1) * N) / 2);

    vector<ll> diff(N);
    for (int i = 0; i < N; ++i) {
        diff[i] = A[i + 1] - A[i];
        if (diff[i] > q) {
            puts("NO");
            return 0;
        }
    }


    for (int i = 0; i < N; ++i) {
        if (abs(q - diff[i]) % N != 0) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");

    return 0;
}
#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;
    ll Nsum = 0;
    rep(i, N + 1) Nsum += i;
    vector<ll> A(N + 1);
    ll Asum = 0;
    rep(i, N) {
        cin >> A[i];
        Asum += A[i];
    }
    A[N] = A[0];
    if (Asum % Nsum != 0) {
        cout << "NO" << endl;
        return 0;
    }
    ll n = Asum / Nsum;
    ll s = 0;
    rep(i, N) {
        ll d = A[i + 1] - A[i];
        // d = n - x - (N - 1) * x
        //   = n - N * x
        // x = (n - d) / N;
        if ((n - d) % N != 0 || n - d < 0) {
            cout << "NO" << endl;
            return 0;
        }
        s += (n - d) / N;
    }
    if (s == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
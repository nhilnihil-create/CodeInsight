#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

#define rep(i, n) for(ll (i) = 0;(i) < (ll)(n);(i)++)

int main(void) {
    ll N;
    vector<ll> A;
    ll count = 0;
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];
    rep(i, N) {
        if(A[i] - 1 > i && A[A[i] - 1] - 1 == i) count++;
    }
    cout << count << endl;
    return 0;
}

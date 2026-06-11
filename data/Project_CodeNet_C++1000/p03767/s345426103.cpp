#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N;
    ll sum = 0;
    vector<ll> A;
    cin >> N;
    A.resize(3 * N);
    for(ll i = 0;i < 3 * N;i++) cin >> A[i];
    sort(A.begin(), A.end(), greater<>());
    for(ll i = 1;i < 2 * N;i += 2) sum += A[i];
    cout << sum << endl;
    return 0;
}

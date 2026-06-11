#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    vector<ll> A;
    A.resize(3);
    cin >> A[0] >> A[1] >> A[2];
    sort(A.begin(), A.end());
    cout << (A.back() % 2) * A[0] * A[1] << endl;
    return 0;
}

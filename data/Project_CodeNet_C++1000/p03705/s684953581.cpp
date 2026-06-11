#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N, A, B;
    cin >> N >> A >> B;
    cout << max(0LL, (B * (N - 1) + A) - (A * (N - 1) + B) + 1) << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

int main() {

    ll N;
    cin >> N;

    vector<ll>A(N), B(N);

    rep(i, N) {
        cin >> A[i] >> B[i];
    }

    ll count = 0;

    for (ll i = N - 1; i >= 0; i--) {
        A[i] += count;
        if (A[i] % B[i] != 0) {
            count += B[i] - (A[i] % B[i]);
        }
    }

    cout << count;

    return 0;
}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll maxA = *max_element(A.begin(), A.end());
    if (maxA < K) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    ll gcd = __gcd(A[0], A[1]);
    for (ll i = 2; i < N; i++) {
        gcd = __gcd(gcd, A[i]);
    }

    if (K % gcd == 0)
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
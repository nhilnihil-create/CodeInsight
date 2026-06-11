#include <algorithm>
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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;

int main() {
    ll N;
    cin >> N;

    vector<ll> T(N);
    rep(i, N) cin >> T[i];

    ll lcm = 1;
    rep(i, N) {
        lcm = lcm / __gcd(lcm, T[i]) * T[i];
        // cout << i << ": " << lcm << endl;
    }

    cout << lcm << endl;

    return 0;
}
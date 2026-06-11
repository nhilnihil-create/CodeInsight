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
    ll X, A, B;
    cin >> X >> A >> B;

    if (-A + B <= 0) {
        cout << "delicious" << endl;
    } else if (-A + B <= X) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }

    return 0;
}
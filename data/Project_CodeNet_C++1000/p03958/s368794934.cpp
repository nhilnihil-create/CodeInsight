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
    ll K, T;
    cin >> K >> T;

    vector<ll> a(T);
    rep(i, T) { cin >> a[i]; }

    while (a.size() > 1) {
        sort(a.begin(), a.end(), greater<int>());

        // repv(a) { cout << *it << " "; }
        // cout << endl;

        if (a.size() == 1) break;

        // cout << a[0] << "," << a[a.size() - 1] << endl;
        a[0] -= a[a.size() - 1];

        a.pop_back();
    }

    cout << max(0LL, a[0] - 1) << endl;

    return 0;
}
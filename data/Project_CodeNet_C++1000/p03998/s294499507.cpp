#include <algorithm>
#include <bitset>
#include <cassert>
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
ll const MAX_N = 100000;
ll const MOD = 1000000007;

int main() {
    vector<string> S(3);
    cin >> S[0] >> S[1] >> S[2];

    char now = 'a';
    vector<ll> cnt(3, 0);
    while (1) {
        ll idx = now - 'a';

        if (cnt[idx] == S[idx].size()) {
            cout << char(idx + 'A') << endl;
            return 0;
        }
        now = S[idx].at(cnt[idx]);
        cnt[idx]++;

        // repv(cnt) cout << *it << " ";
        // cout << endl;
    }

    return 0;
}

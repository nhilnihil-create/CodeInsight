#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

constexpr ll INF = 1LL << 62;
constexpr ll MOD = 1e9 + 7;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> P(N);

    for (auto&& p : P) {
        cin >> p;
        p--;
    }

    ll count = 0;
    for (ll i = 0; i < N / 2; i++) {
        if (i == P[i]) {
            count++;
            swap(P[i], P[i + 1]);
        }
        
        if (N - 1 - i == P[N - 1 - i]) {
            count++;
            swap(P[N - 1 - i], P[N - 1 - i - 1]);
        }
    }

    if (N % 2) {
        if (N / 2 == P[N / 2]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}


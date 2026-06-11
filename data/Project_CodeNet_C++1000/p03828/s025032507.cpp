#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;

template <typename T>
void prime_factor(T n, map<T, T>& m) {
    for (T i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++m[i];
            n /= i;
        }
    }

    if (n != 1) {
        ++m[n];
    }
}

int main() {
    const int MOD = 1e9 + 7;
    int N;
    cin >> N;

    long long nfact = 1;
    map<int, int> m;
    for (int i = 2; i <= N; ++i) {
        prime_factor(i, m);
    }

    long long ans = 1;
    for (auto e : m) {
        ans *= e.second + 1;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
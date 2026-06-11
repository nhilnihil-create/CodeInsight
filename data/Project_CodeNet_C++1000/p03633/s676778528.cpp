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


template <class T>
T gcd(T a, T b) {
    if (a < b) {
        swap(a, b);
    }

    T r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

template <class T>
T lcm(const T& a, const T& b) {
    T n = gcd<T>(a, b);
    if (a > b) {
        return (a / n) * b;
    } else {
        return a * (b / n);
    }
}

int main() {
    int N;
    cin >> N;

    vector<long long> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    long long ans = T[0];
    // cout << ": " << ans << endl;
    for (int i = 1; i < N; i++) {
        ans = lcm(ans, T[i]);
        // cout << ": " << ans << endl;
    }

    cout << ans << endl;

    return 0;
}

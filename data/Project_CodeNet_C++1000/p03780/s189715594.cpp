#include <iostream>
#include <vector>
#include <algorithm>
// #include <string>
// #include <map>
// #include <set>
// #include <cmath>

// #define MOD 1000000007

using namespace std;
// typedef unsigned long long ull;
typedef long long ll;

// void p() {
//     cout << "\n";
// }
// template<class Head, class... Body>
// void p(Head head, Body... body) {
//     cout << head << ",";
//     p(body...);
// }

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (const auto i : v) {
        os << i << " ";
    }
    os << "]";
    return os;
}

int N, K;

bool necessary(int idx, const vector<ll>& a) {
    if (a[idx] >= K) {
        return true;
    }

    vector<vector<bool>> dp(N+1);
    for (int i = 0; i < N+1; ++i) {
        dp[i].resize(K+1, false);
    }
    dp[0][0] = true;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (i == idx || j < a[i]) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = dp[i][j] || dp[i][j-a[i]];
            }
        }
    }

    bool ret = false;
    for (int j = K-a[idx]; j < K; ++j) {
        ret |= dp[N][j];
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    cin >> N >> K;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // for (int i = 0; i < N; ++i) {
    //     cout << i << " necessary:" << necessary(i, a) << endl;
    // }

    int l = -1;
    int u = N;
    while (u - l > 1) {
        int m = (u + l) / 2;
        if (necessary(m, a)) {
            u = m;
        } else {
            l = m;
        }
    }

    cout << l + 1 << endl;

    return 0;
}

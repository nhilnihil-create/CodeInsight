#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P_ii;
typedef pair<string, int> P_si;
typedef long long int ll;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

const int MOD = 1000000007;

int main() {
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    N--;

    for (ll i = 0; i <= N; ++i) {
        ll from = A + C * i - D * (N - i);
        ll to = A + D * i - C * (N - i);
        if (from <= B && B <= to) {
            printf("%s\n", "YES");
            return 0;
        }
    }
    printf("%s\n", "NO");
    return 0;
}


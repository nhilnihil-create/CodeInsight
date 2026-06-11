#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

string A, B;
ll func() {
    if (A == B) {
        return 0;
    } else if (A.size() < B.size()) {
        return -1;
    } else if (A.size() > B.size()) {
        return 1;
    }
    for (ll i = 0; i < A.size(); ++i) {
        ll a = A[i] - '0';
        ll b = B[i] - '0';
        if (a > b) return 1;
        if (a < b) return -1;
    }
    return 0;
}
int main() {
    cin >> A >> B;

    ll ans = func();
    if (ans == 0) {
        cout << "EQUAL" << endl;
    } else if (ans < 0) {
        cout << "LESS" << endl;
    } else if (ans > 0) {
        cout << "GREATER" << endl;
    }

    return 0;
}
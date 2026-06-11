#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <typename T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const long long MOD = 1e9 + 7;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    ll count = 0;
    if(A[0] > X) {
        count += A[0] - X;
        A[0] = X;
    }
    rep(i, 1, N) {
        if(A[i] + A[i - 1] > X) {
            count += A[i] + A[i - 1] - X;
            A[i] -= A[i] + A[i - 1] - X;
        }
    }
    cout << count << endl;
}
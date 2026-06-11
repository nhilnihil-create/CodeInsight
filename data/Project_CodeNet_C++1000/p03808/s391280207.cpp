#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 2100100100;
const int MOD = 1e9 + 7;

ll N, M, K, Q, W, H, L, R, C;
string S;

int main() {
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        sum += A[i];
    }
    A.push_back(A[0]);

    if (sum % (N * (N + 1) / 2) != 0) {
        cout << "NO" << endl;
        return 0;
    }
    ll K = sum / (N * (N + 1) / 2);
    ll ksum = 0;
    for (int i = 0; i < N; i++) {
        ll d = A[i + 1] - A[i];
        if ((K - d) < 0 || (K - d) % N != 0) {
            cout << "NO" << endl;
            return 0;
        } else {
            ksum += (K - d) / N;
        }
    }
    if (K == ksum) {
        cout << "YES" << endl;
        return 0;
    } else {
        cout << "NO" << endl;
        return 0;
    }

    return 0;
}

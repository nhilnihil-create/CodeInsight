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

ll N, M, K, Q, A;

ll dp[51][2505];

int main() {
    cin >> N >> A;

    N = 2 * N - 1;

    if (A == 1 || A == N) {
        cout << "No" << endl;
    } else if (N == 3) {
        cout << "Yes" << endl;
        cout << "1 2 3" << endl;
    } else {
        cout << "Yes" << endl;

        vector<int> ans;
        int l2 = (A == N - 1) ? A - 3 : A + 2;
        int r2 = (A == 2) ? A + 3 : A - 2;
        int i = N;
        for (; i >= 1 && (int)ans.size() < N / 2 - 2; i--) {
            if (i != A && i != A + 1 && i != A - 1 && i != l2 && i != r2) ans.push_back(i);
        }
        ans.push_back(l2);
        ans.push_back(A + 1);
        ans.push_back(A);
        ans.push_back(A - 1);
        ans.push_back(r2);
        for (; i >= 1; i--) {
            if (i != A && i != A + 1 && i != A - 1 && i != l2 && i != r2) ans.push_back(i);
        }
        for (int j = 0; j < N; j++) {
            cout << ans[j];
            if (j != N - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}

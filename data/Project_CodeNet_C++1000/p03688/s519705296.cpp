#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int INF = 1e9;
// const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    set<int> s;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        s.insert(A[i]);
        m[A[i]]++;
    }

    if ((int)s.size() == 1) {
        if (A[0] == N - 1) {
            cout << "Yes\n";
        } else {
            if (A[0] <= N / 2) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    } else if ((int)s.size() == 2) {
        int a = *s.begin();
        if (s.count(a + 1)) {
            if (a + 1 - (m[a]) >= 1 && 2 * (a + 1 - (m[a])) <= m[a + 1]) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            cout << "No\n";
        }
    } else {
        cout << "No\n";
    }
}

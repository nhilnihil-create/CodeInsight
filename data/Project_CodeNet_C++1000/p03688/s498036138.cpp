#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
template <class T> vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
template <typename T> struct edge {
    int to;
    T cost;
    edge(int t, T c) : to(t), cost(c) {}
};
template <typename T> using WGraph = vector<vector<edge<T>>>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int ma = 0, mi = INF;
    rep(i, N) {
        ma = max(A[i], ma);
        mi = min(A[i], mi);
    }
    if(ma - mi > 1) {
        cout << "No" << endl;
    } else if(ma - mi == 0) {
        if(ma + 1 == N || (N / ma > 1)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        int m = 0;
        rep(i, N) {
            if(A[i] == mi)
                m++;
        }
        ma -= m;
        N -= m;
        if(ma > 0 && N / ma > 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
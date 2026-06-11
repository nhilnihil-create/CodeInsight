#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#define DEBUG
#ifdef DEBUG
void debug() { cerr << "\n"; }
template <class T> void debug(const T &x) { cerr << x << "\n"; }
template <class T, class... Args> void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
template <class T> void debugVector(const vector<T> &v) {
    for(const T &x : v) {
        cerr << x << " ";
    }
    cerr << "\n";
}
#else
template <class T, class... Args>
void debug(const T &x, const Args &... args) {}
template <class T> void debugVector(const vector<T> &v) {}
#endif

using ll = long long;
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }
    for(int i = 0; i < N - M + 1; i++) {
        for(int j = 0; j < N - M + 1; j++) {
            bool ok = true;
            for(int r = 0; r < M; r++) {
                for(int c = 0; c < M; c++) {
                    if(A[i + r][j + c] != B[r][c]) {
                        ok = false;
                    }
                }
            }
            if(ok) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}
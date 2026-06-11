#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1e18;
# define len(x) ((int)(x).size())
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define foreps(i, m, n) for(int i = m;i < n;i++)
# define ALL(x) (x).begin(), (x).end()
# define rall(x) (x).rbegin(), (x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    ll N, M; cin >> N >> M;
    vector<vector<char>> A(N, vector<char>(N)), B(M, vector<char>(M));
    rep(i, N) {
        rep(j, N) cin >> A[i][j];
    }
    rep(i, M) {
        rep(j, M) cin >> B[i][j];
    }

    bool ans = false;
    foreps(ly, 0, N) {
        foreps(lx, 0, N) {
            if (ly + M - 1 >= N || lx + M - 1 >= N) continue;

            bool match = true;
            rep(y, M) {
                rep(x, M) {
                    if (A[ly + y][lx + x] != B[y][x]) match = false;
                }
            }
            if (match) ans = true;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
}
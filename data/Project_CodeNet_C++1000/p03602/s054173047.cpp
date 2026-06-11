#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
const ll INF = LLONG_MAX / 2;
const ll MOD = 1e9 + 7;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[N][N];
    ll mat[N][N];
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
            mat[i][j] = A[i][j];
            ans += A[i][j];
        }
    }
    ans /= 2;
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    bool isok = true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            isok &= mat[i][j] == A[i][j];
        }
    }
    if(!isok) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(k == i || k == j)
                    continue;
                if(mat[i][j] == mat[i][k] + mat[k][j]) {
                    ans -= mat[i][j];
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

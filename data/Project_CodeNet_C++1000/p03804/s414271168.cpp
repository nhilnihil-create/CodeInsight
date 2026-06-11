#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> A(N, vector<char>(N)), B(M, vector<char>(M));
    rep(i, N) rep(j, N) cin >> A[i][j];
    rep(i, M) rep(j, M) cin >> B[i][j];
    
    for (int i = 0; i + M <= N; ++i) for (int j = 0; j + M <= N; ++j) {
        bool judge = true;
        rep(k, M) rep(l, M) {
            if (A[i + k][j + l] != B[k][l]) judge = false;
        }
        if (judge) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}

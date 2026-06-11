#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, A[300][300], ans;
constexpr ll inf{ numeric_limits<ll>::max() / 3 };
int main() {
    fill(A[0], A[300], inf);
    cin >> N;
    for(int i{}; i < N; ++i)
        for(int j{}; j < N; ++j)
            cin >> A[i][j];
    for(int k{}; k < N; ++k)
        for(int i{}; i < N; ++i)
            for(int j{}; j < N; ++j)
                if(A[i][j] > A[i][k] + A[k][j]) {
                    cout << -1 << endl;
                    return 0;
                }
    for(int i{}; i < N - 1; ++i)
        for(int j{ i + 1 }; j < N; ++j) {
            ans += A[i][j];
            for(int k{}; k < N; ++k)
                if(i != k && j != k && A[i][j] == A[i][k] + A[k][j]) {
                    ans -= A[i][j];
                    break;
                }
        }
    cout << ans << endl;
}

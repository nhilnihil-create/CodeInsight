#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= M; ++j) {
            int black = i * M + j * N - 2 * i * j;
            if (black == K) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    cout << "No" << endl;
}
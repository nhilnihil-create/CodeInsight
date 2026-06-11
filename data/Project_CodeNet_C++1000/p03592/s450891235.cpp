#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N, M, K; cin >> N >> M >> K;
    if (K == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    string CAN = "No";
    if (K % N == 0 || K % M == 0) CAN = "Yes";
    else {
        rep(i, N+1) {
            rep(j, M+1) {
                if (M * i + N * j - 2 * j * i == K) {
                    CAN = "Yes";
                    goto QUIT;
                }
            }
        }
    }
QUIT:
    cout << CAN << endl;
}

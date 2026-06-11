#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < M + 1; j++) {
            int black = j * N + i * M - i * j * 2;
            if (black == K) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}

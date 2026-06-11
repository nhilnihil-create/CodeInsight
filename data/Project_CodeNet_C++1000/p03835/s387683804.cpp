#include <bits/stdc++.h>

using namespace std;

int K, S;

void solve() {
    int num = 0;
    for (int x = 0; x <= K; ++x) {
        for (int y = 0; y <= K; ++y) {
            if (S - x - y >= 0 && S - x - y <= K) {
                num++;
            }
        }
    }
    printf("%d\n", num);
}

int main() {
    cin >> K >> S;
    solve();
    return 0;
}
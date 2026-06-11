#include <bits/stdc++.h>

using namespace std;

int N;

void solve() {
    int i = 2;
    for (int j = 0;; j++) {
        if (pow(i, j) > N) {
            printf("%d\n", int(pow(i, j - 1)));
            return;
        }
    }
}

int main() {
    cin >> N;
    solve();
    return 0;
}
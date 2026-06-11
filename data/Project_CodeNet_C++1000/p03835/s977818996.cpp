#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int K;
    int S;
    cin >> K >> S;

    int count = 0;
    int m = min(S, K);
    for (int i = 0; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            for (int k = j; k <= m; k++) {
                if (i + j + k == S) {
                    if (i == j && j == k) {
                        count += 1;
                    } else if (i == j || j == k || i == k) {
                        count += 3;
                    } else {
                        count += 6;
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}

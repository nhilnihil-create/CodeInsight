#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N, 0), b(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<int> c(M, 0), d(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> c[i] >> d[i];
    }

    for (int i = 0; i < N; ++i) {
        int minj = 0;
        int mind = abs(c[0] - a[i]) + abs(d[0] - b[i]);
        for (int j = 1; j < M; ++j) {
            int dist = abs(c[j] - a[i]) + abs(d[j] - b[i]);
            if (dist < mind) {
                mind = dist;
                minj = j;
            }
        }
        cout << minj + 1 << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

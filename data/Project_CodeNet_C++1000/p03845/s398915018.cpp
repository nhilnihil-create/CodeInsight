#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<int> T(N, 0);
    int total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
        total += T[i];
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int p, x;
        cin >> p >> x;
        --p;
        cout << total - T[p] + x << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

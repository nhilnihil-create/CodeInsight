#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> T(N, 0);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> T[i]; sum += T[i];
    }
    int M; cin >> M;
    for (int i = 0; i < M; ++i) {
        int p, x, out = sum; cin >> p >> x;
        out -= T[p - 1], out += x;
        printf("%d\n", out);
    }
}

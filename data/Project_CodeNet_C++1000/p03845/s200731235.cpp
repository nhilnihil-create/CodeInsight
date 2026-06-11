#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int N, M, sum = 0; cin >> N;
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T.at(i);
        sum += T.at(i);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int p, x; cin >> p >> x;
        cout << sum - T.at(p-1) + x << endl;
    }
}
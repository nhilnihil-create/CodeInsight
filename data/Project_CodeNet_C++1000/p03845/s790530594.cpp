#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, P, X;
    cin >> N;
    vector<int> T(N), U(N);

    for (int i = 0; i < N; i++) {
        cin >> T.at(i);
        U.at(i) = T.at(i);
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> P >> X;
        T.at(P - 1) = X;
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += T.at(j);
        }
        cout << sum << endl;
        T.at(P - 1) = U.at(P - 1);
    }
}
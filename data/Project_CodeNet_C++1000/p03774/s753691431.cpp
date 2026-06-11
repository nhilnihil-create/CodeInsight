#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N, 0), B(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    vector<int> C(M, 0), D(M, 0), I(M, 0);
    for (int i = 0; i < M; i++) {
        cin >> C[i] >> D[i]; I[i] = i + 1;
    }
    for (int i = 0; i < M; i++) for (int j = i + 1; j < M; j++) if (C[i] == C[j] && D[i] == D[j]) C.erase(C.begin() + j), D.erase(D.begin() + j), I.erase(I.begin() + j);
    for (int i = 0; i < N; i++) {
        long long int mini = 0, ans = 0;
        for (int j = 0; j < C.size(); j++) {
            int tmp = abs(A[i] - C[j]) + abs(B[i] - D[j]);
            if (j == 0) mini = tmp, ans = I[j];
            else if (mini > tmp) mini = tmp, ans = I[j];
        }
        cout << ans << endl;
    }
}

#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<i64>> A(N, vector<i64>(N));
    vector<vector<bool>> used(N, vector<bool>(N, true));
    priority_queue<tuple<i64, int, int>> p;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
            p.emplace(A[i][j], i, j);
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(A[i][j] > A[i][k] + A[k][j]) {
                    cout << -1 << endl;
                    return 0;
                }
                if (A[i][j] == A[i][k] + A[k][j] && used[i][j]) {
                    used[i][j] = used[j][i] = false;
                    used[i][k] = used[k][i] = true;
                    used[k][j] = used[j][k] = true;
                }
            }
        }
    }
    i64 sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(used[i][j]) {
                sum += A[i][j];
            }
        }
    }
    cout << sum / 2 << endl;
    return 0;
}

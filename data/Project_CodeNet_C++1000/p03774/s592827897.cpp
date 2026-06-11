#include<iostream>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    int students[N][2];
    int distance[N];
    int ans[N];
    int checkpoints[M][2];
    for (int i = 0; i < N; i++) {
        cin >> students[i][0];
        cin >> students[i][1];
        distance[i] = 400000000;
    }
    for (int i = 0; i < M; i++) {
        cin >> checkpoints[i][0];
        cin >> checkpoints[i][1];
    }
    for (int i = 0; i < N; i++) {
        int a = students[i][0];
        int b = students[i][1];
        for (int j = 0; j < M; j++) {
            int c = checkpoints[j][0];
            int d = checkpoints[j][1];
            int distance_temp = abs(a - c) + abs(b - d);
            if (distance[i] > distance_temp) {
                distance[i] = distance_temp;
                ans[i] = j + 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}


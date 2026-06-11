#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int T[N];
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    int M; cin >> M;
    int ans_arr[M];
    for (int i = 0; i < M; i++) {
        int P, X; cin >> P >> X;
        int ans = 0;
        for (int j = 0; j < N; j++) {
            if (j == P - 1) {
                ans += X;
            } else {
                ans += T[j];
            }
        }
        ans_arr[i] = ans;
    }
    for (int i = 0; i < M; i++) {
        cout << ans_arr[i] << endl;
    }
}

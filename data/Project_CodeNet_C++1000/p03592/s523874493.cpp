#include <iostream>
using namespace std;

string func(int N, int M, int K) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            int cnt = i * M + j * N - 2 * i * j;
            if (cnt == K) return "Yes";
        }
    }
    return "No";
} 

int main() {
    int N, M, K; cin >> N >> M >> K;
    cout << func(N, M, K) << endl;
}
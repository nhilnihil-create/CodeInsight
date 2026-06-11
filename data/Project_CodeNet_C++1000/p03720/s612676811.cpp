#include<iostream>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    int ans[N] = {0};
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        ans[a - 1]++;
        ans[b - 1]++;
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}

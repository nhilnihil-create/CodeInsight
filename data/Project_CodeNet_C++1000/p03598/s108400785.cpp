#include<iostream>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        ans += min(abs(K - x), abs(x));
    }
    cout << ans * 2 << endl;
}

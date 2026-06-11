#include<iostream>
#include<vector>

using namespace std;

int N, K;

int main() {
    cin >> N >> K;
    int ans = K;
    for (int i = 1; i < N; i++) {
        ans *= K - 1;
    }
    cout << ans << endl;
    return 0;
}
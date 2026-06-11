#include <iostream>
#include <bitset>
using namespace std;
const long long INF = 1LL<<60;

int main() {
    int N, K; cin >> N >> K;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    long long ans = INF;
    for (int bit = 0; bit < (1<<N); bit++) {
        int t = bitset<20>(bit).count();
        if (t < K) continue;
        long long cost = 0;
        int highest = A[0];
        for (int i = 1; i < N; i++) {
            if (bit & (1<<i) && A[i] <= highest) {
                cost += highest++ - A[i] + 1;
            } else {
                highest = max(highest, A[i]);
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}
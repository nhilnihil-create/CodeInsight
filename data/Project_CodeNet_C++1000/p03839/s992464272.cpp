#include<iostream>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5 + 1;

ll A[MAX_N], positive[MAX_N], negative[MAX_N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] >= 0) positive[i] = A[i];
        else negative[i] = A[i];
        positive[i] += positive[i - 1];
        negative[i] += negative[i - 1];
    }
    ll sum = positive[N];
    ll ans = 0;
    for (int i = 1; i <= N - K + 1; i++) {
        if (ans < sum + negative[i + K - 1] - negative[i - 1]) {
            ans = sum + negative[i + K - 1] - negative[i - 1];
        }
        if (ans < sum - positive[i + K - 1] + positive[i - 1]) {
            ans = sum - positive[i + K - 1] + positive[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}
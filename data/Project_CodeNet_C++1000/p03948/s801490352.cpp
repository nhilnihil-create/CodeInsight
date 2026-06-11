#include <iostream>

using namespace std;

int main(void) {
    int N, T;
    cin >> N >> T;
    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int min_buy = A[0];
    int max_sell = 0;
    int ans = 1;
    for (int i = 1; i < N; ++i) {
        int sell = A[i] - min_buy;
        min_buy = min(min_buy, A[i]);
        if (sell == max_sell) {
            ans++;
        }
        max_sell = max(max_sell, sell);
    }

    cout << ans << endl;
    return 0;
}
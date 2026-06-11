#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K, X, Y;
    cin >> N;
    cin >> K;
    cin >> X;
    cin >> Y;

    long long ans = 0;

    for (int i = 0; i < N; ++i) {
        if (i < K) {
            ans += X;
        } else {
            ans += Y;
        }
    }

    cout << ans << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, X, Y;
    cin >> N;
    cin >> K;
    cin >> X;
    cin >> Y;

    int ans = 0;
    if (N > K)
    {
        ans = K * X + (N - K) * Y;
    }
    else
    {
        ans = N * X;
    }
    cout << ans << endl;
    return 0;
}
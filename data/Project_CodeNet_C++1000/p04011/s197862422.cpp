#include <bits/stdc++.h>
using namespace std;
const int mn = 1000000007;

int main(void)
{
    int N, K, X, Y;

    cin >> N >> K >> X >> Y;

    int ans = 0;

    if(N > K)
    {
        ans += K * X;
        ans += (N-K) * Y;
    }
    else
    {
        ans += N * X;
    }
    

    cout << ans << endl;

    return 0;
}


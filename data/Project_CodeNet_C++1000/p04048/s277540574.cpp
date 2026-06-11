#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long N, X;
    cin >> N >> X;
    if (N == X) 
    {
        cout << 3 * N << endl;
        return 0;
    }


    long long ans = N;
    long long l = min(X, N - X);
    long long L = N - 2 * l;

    ans += l;
    while (L % l != 0)
    {
        ans += (L / l) * l * 2;
        ans += l + L%l;

        long long LL = L;
        L = l - L % l;
        l = LL%l;
    }
    ans += L * 2;
    cout << ans << endl;
    return 0;
}
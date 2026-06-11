#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

int main()
{
    ll N;
    int digits = 1e5;
    cin >> N;
    for (ll i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            ll A = i;
            ll B = N / i;
            int maxDigits = max((int)to_string(A).length(), (int)to_string(B).length());
            digits = min(digits, maxDigits);
        }
    }

    cout << digits << endl;

    return 0;
}
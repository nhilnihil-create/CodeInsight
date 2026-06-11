#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];

    ll rui = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        A[i] += rui;
        if (A[i] % B[i] != 0)
        {
            rui += B[i] - A[i] % B[i];
        }
    }

    cout << rui << endl;
}
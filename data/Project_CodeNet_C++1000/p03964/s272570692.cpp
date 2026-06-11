#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    ll T,A;
    cin >> T >> A;
    for(int i = 1;i < n;i++)
    {
        ll t,a;
        cin >> t >> a;
        if(t < T || a < A)
        {
            ll k = max(ceil((long double)T / t),ceil((long double)A / a));
            t *= k;
            a *= k;
        }
        T = t;
        A = a;
    }
    cout << A + T << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll I, ll O, ll T, ll L, ll J, ll S, ll Z)
{
    if(I < 0 || L < 0 || J < 0)
        return -3;
    return I / 2 * 2 + O + L / 2 * 2 + J / 2 * 2;
}

ll I, O, T, L, J, S, Z;

int main()
{
    cin >> I >> O >> T >> L >> J >> S >> Z;
    cout << max(f(I, O, T, L, J, S, Z), f(I - 1, O, T, L - 1, J - 1, S, Z) + 3) << "\n";
    return 0;
}

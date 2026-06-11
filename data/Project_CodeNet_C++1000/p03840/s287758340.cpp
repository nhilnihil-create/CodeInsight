#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll I, O, T, J, L, S, Z;
ll mx;

int main()
{
    cin >> I >> O >> T >> J >> L >> S >> Z;
    mx = I / 2 * 2 + J / 2 * 2 + L / 2 * 2;
    if (I >= 1 && J >= 1 && L >= 1)
        mx = max(mx, (I - 1) / 2 * 2 + (J - 1) / 2 * 2 + (L - 1) / 2 * 2 + 3);
    mx += O;
    cout << mx << endl;
    return 0;
}

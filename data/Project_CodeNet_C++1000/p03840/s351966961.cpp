#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long I, O, T, J, L, S, Z, ans = 0;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    ans += O + (I & ~1) + (J & ~1) + (L & ~1);
    if ((I&1) && (J&1) && (L&1)) ans += 3;
    else if ((I&1) && (J&1) && L) ans += 1;
    else if ((J&1) && (L&1) && I) ans += 1;
    else if ((L&1) && (I&1) && J) ans += 1;
    cout << ans << endl;
    return 0;
}
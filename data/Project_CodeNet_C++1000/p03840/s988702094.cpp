#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    LL I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;

    LL ans = O*2;

    LL sm = I%2+J%2+L%2;
    if (I > 0 && J > 0 && L > 0 && sm >= 2) {
        ans += 6;
        I--;
        J--;
        L--;
    }

    ans += (J/2)*4;
    J &= 1;

    ans += (L/2)*4;
    L &= 1;

    ans += (I/2)*4;
    I &= 1;

    cout << ans/2 << endl;

    return 0;
}

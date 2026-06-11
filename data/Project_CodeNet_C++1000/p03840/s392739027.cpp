#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll ans, I, O, T, S, L, J, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    ans = O;
    if (I && J && L) {
        vector<int> a(3);
        a[0] = I%2;
        a[1] = J%2;
        a[2] = L%2;
        if ((int)count(a.begin(), a.end(), 1) >= 2) {
            ans += 3;
            I--;J--;L--;
        }
    }
    ans += I/2*2+J/2*2+L/2*2;
    cout << ans << endl;
    return 0;
}

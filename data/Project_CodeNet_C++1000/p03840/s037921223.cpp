#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int I, O, T, J, L, S, Z;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> I >> O >> T >> J >> L >> S >> Z;
    ll ans = 0;
    if(I && J && L && I % 2 + J % 2 + L % 2 >= 2){
        I--;
        J--;
        L--;
        ans += 3;
    }
    ans += J / 2 * 2;
    ans += L / 2 * 2;
    ans += I / 2 * 2;
    ans += O;
    cout << ans << endl;
}

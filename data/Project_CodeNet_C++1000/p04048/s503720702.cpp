#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t n, x; cin >> n >> x;

    int64_t ans = x + (n - x);
    int64_t a = x, b = (n - x);

    while(a) {
        if(a > b) swap(a, b);
        int64_t tmp = b % a;
        ans += 2 * a * (b / a);
        if(tmp == 0) ans -= a;
        b = a; a = tmp;
    }

    cout << ans << endl;
    return 0;
}
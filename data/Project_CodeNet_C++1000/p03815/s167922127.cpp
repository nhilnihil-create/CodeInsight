#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long x, ans = 0;
    cin >> x;
    ans = x/11 * 2;
    if(x%11 == 0){}
    else if(x%11 <= 6) ans += 1;
    else if(x%11 > 6) ans += 2;
    cout << ans << endl;
}
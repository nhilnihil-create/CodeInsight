
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int64_t a, b, x;
    cin >> a >> b >> x;
    int64_t ans;
    if (a % x == 0) ans ++;
    ans += b / x - a / x;
    
    cout << ans << endl;
}
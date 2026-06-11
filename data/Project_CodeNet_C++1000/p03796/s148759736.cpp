#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n, ans = 1;
    cin >> n;
    for (int i=1; i<=n; i++){
        ans *= i;
        ans %= (int)(pow(10, 9) + 7);
    }
    cout << ans << endl;
    return 0;
}
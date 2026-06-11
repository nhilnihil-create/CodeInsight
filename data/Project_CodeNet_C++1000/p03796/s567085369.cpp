#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    ll ans = 1;
    ll div;
    div = pow(10,9) + 7;
    for(int i = 1; i <= N; i++){
        ans *= i;
        ans = ans % div;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll mod = pow(10, 9) + 7;

    ll N;
    cin >> N;

    ll ans = 1;

    for(ll i = 1; i <= N; i++){
        ans *= i;
        ans %= mod;
    }

    cout << ans << endl;
}
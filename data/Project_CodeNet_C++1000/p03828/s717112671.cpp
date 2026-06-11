#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll mod = pow(10, 9) + 7;

    vector<ll> x(1000);

    ll N;
    cin >> N;

    ll ans = 1;

    for(ll i = 2LL; i <= N; i++) {
        ll n = i;

        for(ll j = 2; j * j <= n; j++) {
            while(n % j == 0) {
                x[j]++;
                n /= j;
            }
        } 

        if(n != 1) x[n]++;
    }

    for(int i = 0; i < 1000; i++) {
        ans *= x[i] + 1LL;
        ans %= mod;
    }

    cout << ans << endl;
}
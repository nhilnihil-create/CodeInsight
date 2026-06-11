#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
ll mod = 1000000007;
 
ll Prime_Factorization(ll N, ll *fac, ll mod) {
    ll N_ = N;
    ll ans = 1;
    for (ll i = 2; i*i <= N_; i++) {
        while (N % i == 0) {
            fac[i]++;
            N /= i;
        }
        ans *= fac[i]+1;
        ans %= mod;
    }
    if (N > 1) {
        fac[N]++;
        ans *= 2;
    }
    return ans;
}
 
int main() {
    ll N;  cin >> N;
    ll N_ = N;
 
    ll ans = 1;
    ll *cnt = new ll[N+1];
    for (ll i = 0; i <= N; i++)
        cnt[i] = 0;
 
    for (ll n = 2; n <= N; n++) {
        Prime_Factorization(n, cnt, mod);
    }
 
    for (ll i = 2; i <= N; i++) {
        ans *= cnt[i]+1;
        ans %= mod;
    }
 
    cout << ans << endl;
 
    return 0;
}
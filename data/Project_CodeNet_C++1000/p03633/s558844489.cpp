#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

int main() {
    int N;
    cin >> N;
    
    vec<ll> T(N);
    ll ans = 1;
    rep(i, N) {
        cin >> T[i];
        ans = lcm(ans,T[i]);
    }

    cout << ans << endl;

}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define rep1(i, n) for(int i = 1; i <= (int) n; i++)

const ll mod = 1e9+7;

int main() {
    ll n,m;
    cin >> n >> m;
    if (abs(n-m) > 1) {
        cout << 0 << endl;
        return 0;
    }
    ll dog = 1;
    ll mon = 1;
    rep1(i,n) {
        dog = dog*i%mod;
    }
    rep1(i,m) {
        mon = mon*i%mod;
    }
    ll ans = dog*mon % mod;
    if (n == m) {
        ans = 2*ans%mod;
    }
    cout << ans << endl;
    return 0;
}
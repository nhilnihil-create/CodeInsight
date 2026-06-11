#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

ll factorial(ll n,ll m){
    ll r = 1;
    for(ll i=1;i<=n;i++) r = (i*r)%m;
    return r%m;
}

int main() {

    ll mod = 1000000007;
    ll N,M;
    cin >> N >> M;
    ll out = 0;
    if(abs(N-M)<2){
        ll n = factorial(N,mod);
        ll m = factorial(M,mod);
        out = (n*m)%mod;
        if(N==M) out = (out*2)%mod;
    }
    cout << out << endl;
    return 0;
}

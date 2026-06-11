#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <complex>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <iomanip>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

const ll INF = 100000000;
const ll MOD = 1000000007;

ll pow_mod(ll a,ll b,ll mod){
    if(a%mod==0){
        return 0;
    }

    ll x = 1;

    while(b>0){
        if(b&1){
            x = (x * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return x;
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    //問題文中の添え字が0-indexか1-indexか確認!

    ll k;
    std::cin >> k;
    ll n = 50;
    ll a[50];
    rep(i,0,50){
        a[i] = i + (k / 50);
    }
    rep(i,0,k%50){
        a[i] += n;
        rep(j, 0, n)
        {
            if(i!=j){
                a[j]--;
            }
        }
    }
    std::cout << n << "\n";
    rep(i,0,n){
        std::cout << a[i] << " ";
    }
    return 0;
}
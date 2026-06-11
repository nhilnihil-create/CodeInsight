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
#include <limits.h>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

const ll MOD = 1000000007;

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    //問題文中の添え字が0-indexか1-indexか確認!

    ll n;
    std::cin>>n;
    std::vector<ll> a(n);
    rep(i,0,n){
        std::cin>>a[i];
    }
    ll ans=0;
    for(ll i=n-1;i>1;i--){
        if(a[i]==i+1){
            a[i]^=a[i-1];
            a[i-1]^=a[i];
            a[i]^=a[i-1];
            ans++;
        }
    }

    if(a[0]==1||a[1]==2){
        ans++;
    }
    std::cout<<ans;
    return 0;
}
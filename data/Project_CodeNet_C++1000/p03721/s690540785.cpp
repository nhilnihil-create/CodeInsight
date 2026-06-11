#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> val(1e+5 + 10, 0);
 
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        val[a] += b;
    }
 
    ll ans;
    for (int i = 1; i <= 1e+5+10; i++) {
        k -= val[i];
        if (k <= 0) {
            ans = i;
            break;
        }
 
    }
 
    cout << ans << endl;
    return 0;
}
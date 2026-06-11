#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int M = 1e5 + 10;
ll num[M];
ll n , a , b;
bool cheak(ll x) {
    ll cn = a - b;
    ll gl = 0;
    for(int i = 0 ; i < n ; i++) {
        ll gg = num[i] - b * x;
        if(gg <= 0) continue;
        else {
            gl += gg / cn;
            gl += (gg % cn != 0);
            if(gl > x) return false;
        }
    }
    if(gl > x) return false;
    return true;
}
int main() {
    scanf("%lld%lld%lld" , &n , &a , &b);
    for(int i = 0 ; i < n ; i++) {
        scanf("%lld" , &num[i]);
    }
    ll l = 0 , r = 1e9;
    ll ans = r;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(cheak(mid)) r = mid - 1 , ans = min(mid , ans);
        else l = mid + 1;
    }
    printf("%lld\n" , ans);
    return 0;
}
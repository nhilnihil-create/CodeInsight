#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    long double q,h,s,d;
    cin >> q >> h >> s >> d;
    ll n;
    cin >> n;
    q *= 4;
    h *= 2;
    d /= 2;
    ll ans = 0;
    if(min({q,h,d,s}) == d){
        ans += n/2 *(2*d);
        n %= 2;
    }
    ans += min({q,h,s})*n;
    cout << ans << endl;
    return 0;
}
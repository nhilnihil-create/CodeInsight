#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll q,h,s,d;
    ll n;
    cin >> q >> h >> s >> d >> n;
    ll ans = 0;
    ans += (n/2)*(min({8*q,4*h,2*s,d}));
    n -= (n/2)*2;
    ans += (n/1)*(min({4*q,2*h,s}));
    cout << ans << endl;
}

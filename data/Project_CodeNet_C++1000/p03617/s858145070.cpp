#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d;
    cin >> n;
    ll ans = (n/2)*min(8*q, min(4*h, min(2*s, d))) + (n%2)*min(4*q, min(2*h, s));
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll q, h, s, d;
    cin >> q >> h >> s >> d;
    ll n;
    cin >> n;
    h = min(2*q, h);
    s = min(2*h, s);
    d = min(2*s, d);
    cout << (n/2*d + (n&1)*s) << endl;
}

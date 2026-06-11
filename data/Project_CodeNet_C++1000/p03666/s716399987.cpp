#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    
    b = abs(b - a);
    
    ll period = c+d;
    ll w = (d-c) * (n-1);
    
    ll up=d*(n-1);
    if (b > up) {
        cout << "NO" << endl;
        return 0;
    }
    
    if (w >= period) {
        cout << "YES" << endl;
        return 0;
    }
    
    ll base;
    if (n%2==0) {
        base = (period-w)/2;
    } else {
        base = period - w/2;
    }
    
    if ((b - base + period) % period <= w) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    
    return 0;
}

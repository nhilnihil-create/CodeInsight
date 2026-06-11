#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)

int main() {
    ll x, y;
    cin >> x >> y;
    ll ans = 1000000100;

    ll x_inv = -x, y_inv = -y;
    if(x_inv <= y) {
        ans = min(1+y-x_inv, ans);
    }
    if(x <= y) {
        ans = min(y-x, ans);
    }
    if(x <= y_inv) {
        ans = min(y_inv-x+1, ans);
    }
    if(x_inv <= y_inv) {
        ans = min(y_inv-x_inv+2, ans);
    }
    cout << ans << endl;
    
    return 0;
}
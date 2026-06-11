#include <bits/stdc++.h>

using namespace std;


int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    if(a == 1 && b == 1 && c == 1) {
        cout << 0 << "\n";
        return 0;
    }
    if(a == b && b == c && c == a) {
        cout << -1 << "\n";
        return 0;
    }
    int ans = 0;
    if(a % 2 == 1 && b % 2 == 1 && c % 2 == 1) {
        int ha = (b + c) / 2;
        int hb = (c + a) / 2;
        int hc = (a + b) / 2;
        a = ha;
        b = hb;
        c = hc;
        ans++;
    }
    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        int ha = (b + c) / 2;
        int hb = (c + a) / 2;
        int hc = (a + b) / 2;
        a = ha;
        b = hb;
        c = hc;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}